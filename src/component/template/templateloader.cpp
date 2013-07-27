#include "templateloader.h"
#include "io/ioserver.h"
#include "component/template/templatecontainer.h"

namespace Component {
/// namespaces
using namespace IO;
using namespace Record;
    
/// declare the loadEntrys
TemplateLoader::LoadClassEntryDictionary TemplateLoader::loadEntrys;
/// declare the default attr
Util::StringAtom TemplateLoader::ValueAttr;
Util::StringAtom TemplateLoader::IdAttr;
Util::StringAtom TemplateLoader::DefaultAttr;
Util::StringAtom TemplateLoader::ParentAttr;
Util::StringAtom TemplateLoader::IndexAttr;
  
/// load class
void TemplateLoader::Load(Ptr<IO::XmlReader> &xmlReader, const Util::StringAtom& n, TemplateRecordPtr &ref, TemplateContainer& container){
    IndexT idx = loadEntrys.FindIndex(n);
    if (idx != InvalidIndex) {
        LoadClassEntry entry = loadEntrys.ValueAtIndex(idx);
        (*entry)(xmlReader, ref, container);
    }else{
        LOGE("wrong class name %s, we can not find load entry!", n.Value());
    }
}

/// load record
void TemplateLoader::LoadRecord(const IO::URI &uri, TemplateContainer& container){
    Ptr<Stream> stream = IO::IoServer::Instance()->CreateStream(uri);
    if (stream.isvalid() && stream->Open()){
        Ptr<IO::XmlReader> xmlReader = IO::XmlReader::Create();
        xmlReader->SetStream(stream);
        if (xmlReader->Open()) {
            
            if(xmlReader->SetToFirstChild()) do {
                Util::StringAtom nodeName = xmlReader->GetCurrentNodeName();
                if (nodeName.IsValid()) {
                    TemplateRecordPtr ptr = NULL;
                    Load(xmlReader, nodeName, ptr, container);
                    if (ptr) {
                        container.AddRecord(ptr);
                    }
                }
            } while (xmlReader->SetToNextChild());
            
            xmlReader->Close();
        }
        stream->Close();
    }
}
    
#include <float.h>
static float AsFloat(const Util::String &v){
    if (v.IsValidFloat()) {
        return v.AsFloat();
    }
    
    if (v == Util::String("MAX")) {
        return FLT_MAX;
    }else if(v == Util::String("MIN")){
        return FLT_MIN;
    }
    
    return 0;
}

template<>
void TemplateLoader::LoadType<uint8_t>(Ptr<IO::XmlReader> &xmlReader, uint8_t &ref, const Util::StringAtom &attr, TemplateContainer& container){
    ref = xmlReader->GetInt(attr.Value());
}
    
template<>
    void TemplateLoader::LoadType<uint16_t>(Ptr<IO::XmlReader> &xmlReader, uint16_t &ref, const Util::StringAtom &attr, TemplateContainer& container){
    ref = xmlReader->GetInt(attr.Value());
}
    
template<>
void TemplateLoader::LoadType<uint32_t>(Ptr<IO::XmlReader> &xmlReader, uint32_t &ref, const Util::StringAtom &attr, TemplateContainer& container){
    ref = xmlReader->GetInt(attr.Value());
}
    
template<>
void TemplateLoader::LoadType<uint64_t>(Ptr<IO::XmlReader> &xmlReader, uint64_t &ref, const Util::StringAtom &attr, TemplateContainer& container){
    ref = atoll(xmlReader->GetString(attr.Value()).AsCharPtr());
}
 
template<>
void TemplateLoader::LoadType<int8_t>(Ptr<IO::XmlReader> &xmlReader, int8_t &ref, const Util::StringAtom &attr, TemplateContainer& container){
    ref = xmlReader->GetInt(attr.Value());
}
    
template<>
void TemplateLoader::LoadType<int16_t>(Ptr<IO::XmlReader> &xmlReader, int16_t &ref, const Util::StringAtom &attr, TemplateContainer& container){
    ref = xmlReader->GetInt(attr.Value());
}
    
template<>
void TemplateLoader::LoadType<int32_t>(Ptr<IO::XmlReader> &xmlReader, int32_t &ref, const Util::StringAtom &attr, TemplateContainer& container){
    ref = xmlReader->GetInt(attr.Value());
}
    
template<>
void TemplateLoader::LoadType<int64_t>(Ptr<IO::XmlReader> &xmlReader, int64_t &ref, const Util::StringAtom &attr, TemplateContainer& container){
    ref = atoll(xmlReader->GetString(attr.Value()).AsCharPtr());
}
    
template<>
void TemplateLoader::LoadType<float>(Ptr<IO::XmlReader> &xmlReader, float &ref, const Util::StringAtom &attr, TemplateContainer& container){
    ref = xmlReader->GetFloat(attr.Value());
}
    
template<>
void TemplateLoader::LoadType<double>(Ptr<IO::XmlReader> &xmlReader, double &ref, const Util::StringAtom &attr, TemplateContainer& container){
    ref = atof(xmlReader->GetString(attr.Value()).AsCharPtr());
}
    
template<>
void TemplateLoader::LoadType<bool>(Ptr<IO::XmlReader> &xmlReader, bool &ref, const Util::StringAtom &attr, TemplateContainer& container){
    ref = xmlReader->GetInt(attr.Value());
}
    
template<>
void TemplateLoader::LoadType<Util::StringAtom>(Ptr<IO::XmlReader> &xmlReader, Util::StringAtom &ref, const Util::StringAtom &attr, TemplateContainer& container){
    ref = xmlReader->GetString(attr.Value());
}
    
template<>
void TemplateLoader::LoadType<Util::String>(Ptr<IO::XmlReader> &xmlReader, Util::String &ref, const Util::StringAtom &attr, TemplateContainer& container){
    ref = xmlReader->GetString(attr.Value());
}
    
template<>
void TemplateLoader::LoadType<Record::STargetFilters>(Ptr<IO::XmlReader> &xmlReader, Record::STargetFilters &ref,
                                                          const Util::StringAtom &attr, Component::TemplateContainer &container){
    
    Util::String value = xmlReader->GetString(attr.Value());
    Util::Array<Util::String> filterGroups;
    value.Tokenize(Util::String(";"), filterGroups);
    for (IndexT gpIdx = 0; gpIdx < filterGroups.Size(); ++gpIdx) {
        const Util::String& filters = filterGroups[gpIdx];
        if (filters != "-" && filters.Length() > 0) {
            Record::ETargetFilterState state = (Record::ETargetFilterState)(gpIdx);
            Util::Array<Util::String> filtersToTarget;
            filters.Tokenize(Util::String(","), filtersToTarget);
            for (IndexT filterIdx = 0; filterIdx < filtersToTarget.Size(); ++filterIdx) {
                Record::ETargetFilter filter = Record::EETargetFilter::Value(filtersToTarget[filterIdx]);
                ref.Filters.Add(filter, state);
            }
        }
    }
}
    
template<>
void TemplateLoader::LoadType<Record::SColor>(Ptr<IO::XmlReader> &xmlReader, Record::SColor &ref, const Util::StringAtom &attr, Component::TemplateContainer &container){
    Util::String value = xmlReader->GetString(attr.Value());
    Util::Array<Util::String> colors;
    value.Tokenize(Util::String(","), colors);
    switch (colors.Size()) {
        case 4:
            ref.a = colors[3].AsInt();
        case 3:
            ref.b = colors[2].AsInt();
        case 2:
            ref.g = colors[1].AsInt();
        case 1:
            ref.r = colors[0].AsInt();
        default:
            break;
    }
}
template<>
void TemplateLoader::LoadType<Record::SVector2>(Ptr<IO::XmlReader> &xmlReader, Record::SVector2 &ref, const Util::StringAtom &attr, Component::TemplateContainer &container){
    Util::String value = xmlReader->GetString(attr.Value());
    Util::Array<Util::String> vectors;
    value.Tokenize(Util::String(","), vectors);
    switch (vectors.Size()) {
        case 2:
            ref.y = vectors[1].AsInt();
        case 1:
            ref.x = vectors[0].AsInt();
        default:
            break;
    }
}
    
template<>
void TemplateLoader::LoadType<Record::SVector3>(Ptr<IO::XmlReader> &xmlReader, Record::SVector3 &ref, const Util::StringAtom &attr, Component::TemplateContainer &container){
    Util::String value = xmlReader->GetString(attr.Value());
    Util::Array<Util::String> vectors;
    value.Tokenize(Util::String(","), vectors);
    switch (vectors.Size()) {
        case 3:
            ref.z = vectors[2].AsInt();
        case 2:
            ref.y = vectors[1].AsInt();
        case 1:
            ref.x = vectors[0].AsInt();
        default:
            break;
    }
}
     
template<>
void TemplateLoader::LoadType<Record::SVector4>(Ptr<IO::XmlReader> &xmlReader, Record::SVector4 &ref, const Util::StringAtom &attr, Component::TemplateContainer &container){
    Util::String value = xmlReader->GetString(attr.Value());
    Util::Array<Util::String> vectors;
    value.Tokenize(Util::String(","), vectors);
    switch (vectors.Size()) {
        case 4:
            ref.w = vectors[3].AsInt();
        case 3:
            ref.z = vectors[2].AsInt();
        case 2:
            ref.y = vectors[1].AsInt();
        case 1:
            ref.x = vectors[0].AsInt();
        default:
            break;
    }
}
    
template<>
void TemplateLoader::LoadType<Record::SIntRange>(Ptr<IO::XmlReader> &xmlReader, Record::SIntRange &ref, const Util::StringAtom &attr, Component::TemplateContainer &container){
    Util::String value = xmlReader->GetString(attr.Value());
    Util::Array<Util::String> vectors;
    value.Tokenize(Util::String(","), vectors);
    switch (vectors.Size()) {
        case 2:
            ref.max = vectors[1].AsInt();
        case 1:
            ref.min = vectors[0].AsInt();
        default:
            break;
    }
}
     
template<>
void TemplateLoader::LoadType<Record::SFloatRange>(Ptr<IO::XmlReader> &xmlReader, Record::SFloatRange &ref, const Util::StringAtom &attr, Component::TemplateContainer &container){
    Util::String value = xmlReader->GetString(attr.Value());
    Util::Array<Util::String> vectors;
    value.Tokenize(Util::String(","), vectors);
    switch (vectors.Size()) {
        case 2:
            ref.max = vectors[1].AsFloat();
        case 1:
            ref.min = vectors[0].AsFloat();
        default:
            break;
    }
}
         
template<>
void TemplateLoader::LoadType<Record::SRotator>(Ptr<IO::XmlReader> &xmlReader, Record::SRotator &ref, const Util::StringAtom &attr, Component::TemplateContainer &container){
    Util::String value = xmlReader->GetString(attr.Value());
    Util::Array<Util::String> vectors;
    value.Tokenize(Util::String(","), vectors);
    switch (vectors.Size()) {
        case 3:
            ref.pitch = AsFloat(vectors[2]);
            ref.roll = AsFloat(vectors[1]);
            ref.yaw = AsFloat(vectors[0]);
            break;
        case 2:
            ref.roll = AsFloat(vectors[1]);
            ref.yaw = AsFloat(vectors[0]);
            break;
        case 1:
            float vf = AsFloat(vectors[0]);
            ref.roll = ref.yaw = ref.pitch = vf;
            break;
    }
}
    
template<>
void TemplateLoader::LoadType<Record::SActorKey>(Ptr<IO::XmlReader> &xmlReader, Record::SActorKey &ref, const Util::StringAtom &attr, Component::TemplateContainer &container){
    ref.actor = xmlReader->GetString(attr.Value());
}
      
template<>
void TemplateLoader::LoadType<Record::STimeOfDay>(Ptr<IO::XmlReader> &xmlReader, Record::STimeOfDay &ref, const Util::StringAtom &attr, Component::TemplateContainer &container){
    Util::String value = xmlReader->GetString(attr.Value());
    Util::Array<Util::String> vectors;
    value.Tokenize(Util::String(","), vectors);
    switch (vectors.Size()) {
        case 3:
            ref.second= vectors[2].AsInt();
        case 2:
            ref.minute = vectors[1].AsInt();
        case 1:
            ref.hour = vectors[0].AsInt();
        default:
            break;
    }
}
       
template<>
void TemplateLoader::LoadType<Record::SBaseRange>(Ptr<IO::XmlReader> &xmlReader, Record::SBaseRange &ref, const Util::StringAtom &attr, Component::TemplateContainer &container){
    Util::String value = xmlReader->GetString(attr.Value());
    Util::Array<Util::String> vectors;
    value.Tokenize(Util::String(","), vectors);
    switch (vectors.Size()) {
        case 2:
            ref.range = vectors[1].AsInt();
        case 1:
            ref.base = vectors[0].AsInt();
        default:
            break;
    }
}
        
template<>
void TemplateLoader::LoadType<Record::SFloatRangeMirror>(Ptr<IO::XmlReader> &xmlReader, Record::SFloatRangeMirror &ref, const Util::StringAtom &attr, Component::TemplateContainer &container){
    Util::String value = xmlReader->GetString(attr.Value());
    Util::Array<Util::String> vectors;
    value.Tokenize(Util::String(","), vectors);
    switch (vectors.Size()) {
        case 4:
            ref.positiveMin = AsFloat(vectors[3]);
        case 3:
            ref.positiveMax = AsFloat(vectors[2]);
        case 2:
            ref.negtiveMin = AsFloat(vectors[1]);
        case 1:
            ref.negtiveMax = AsFloat(vectors[0]);
        default:
            break;
    }
}
         
template<>
void TemplateLoader::LoadType<Record::SActorTerm>(Ptr<IO::XmlReader> &xmlReader, Record::SActorTerm &ref, const Util::StringAtom &attr, Component::TemplateContainer &container){
    Util::String value = xmlReader->GetString(attr.Value());
    Util::Array<Util::String> vectors;
    value.Tokenize(Util::String(" "), vectors);
    switch (vectors.Size()) {
        case 2:
            ref.value = vectors[1];
        case 1:
            ref.type = EEActorTermType::Value(vectors[0]);
        default:
            break;
    }
}
    
/// load head of class
template<typename TYPE>
void LoadRecordHead(Ptr<IO::XmlReader> &xmlReader, TemplateLoader::TemplateRecordPtr &ref, Component::TemplateContainer &container){
    TYPE * data = NULL;
    /// set the id
    if (xmlReader->HasAttr(TemplateLoader::IdAttr.Value())) {
        Util::StringAtom id = xmlReader->GetString(TemplateLoader::IdAttr.Value());
        data = new TYPE();
        data->Id = id;
        ref = data;
    }else {
        return;
    }
    
    /// init from default
    const Record::TemplateRecord* defaultRecord = container.FindDefaultRecord(data);
    if (defaultRecord) {
        TYPE *defaultDerived = (TYPE*)(defaultRecord);
        if (defaultDerived) {
            *data = *defaultDerived;
        }
    }else if (xmlReader->HasAttr(TemplateLoader::DefaultAttr.Value())){
        container.AddDefaultRecord(data);
    }
    
    /// init from parent
    if(xmlReader->HasAttr(TemplateLoader::ParentAttr.Value())) {
        Util::StringAtom parent = xmlReader->GetString(TemplateLoader::ParentAttr.Value());
        const Record::TemplateRecord * recordParent = container.FindRecord(parent, (Record::ERecordType)(data->RecordType));
        if(recordParent && recordParent != defaultRecord) {
            TYPE *parntDerived = (TYPE*)(recordParent);
            *data = *parntDerived;
        }
    }
}

template<typename TYPE >
bool LoadRecordBody(Ptr<IO::XmlReader> &xmlReader, const Util::StringAtom& member, const Util::StringAtom& attr,
                    TYPE &ref, Component::TemplateContainer &container){
    LOGE("not implement the (%s, %s) in LoadRecordBody for %s", member.Value(), attr.Value(),
         EERecordType::NameAt(ref.RecordType).Value());
    return false;
}

template<>
bool LoadRecordBody<Record::TemplateRecord>(Ptr<IO::XmlReader> &xmlReader, const Util::StringAtom& member, const Util::StringAtom& attr,
                                            Record::TemplateRecord &ref, Component::TemplateContainer &container){
    
    if (member != TemplateLoader::IdAttr && member != TemplateLoader::ParentAttr
        && member != TemplateLoader::ParentAttr && member != TemplateLoader::DefaultAttr
        && member  != TemplateLoader::IndexAttr ) {
        LOGE("not implement the (%s, %s) in LoadRecordBody for %s", member.Value(), attr.Value(),
             EERecordType::NameAt(ref.RecordType).Value());
    }
    
    return false;
}
   
/// LoadType for enum
#undef JEnumBegin
#undef JEnumBeginWith
#undef JEnumValueWith
#undef JEnumValue
#undef JEnumEnd
#define JEnumBegin(NameSpace, Enum) \
    template<>\
    void TemplateLoader::LoadType< NameSpace::Enum >(Ptr<IO::XmlReader> &xmlReader, NameSpace::Enum &ref, const Util::StringAtom &attr, TemplateContainer& container){ \
        ref = Component::TemplateEnum< NameSpace::Enum >::Value( xmlReader->GetString(attr.Value()) );

#define JEnumBeginWith(NameSpace, Enum, TYPE) JEnumBegin(NameSpace, Enum)
#define JEnumValueWith(Enum, n, i)
#define JEnumValue(Enum, n)
#define JEnumEnd(NameSpace, Enum) }
#include "component/template/record/recordenum.h"

/// LoadType for flag
#undef JEnumBegin
#define JEnumBegin(NameSpace, Enum) \
    template<>\
    void TemplateLoader::LoadType< NameSpace::Enum >(Ptr<IO::XmlReader> &xmlReader, NameSpace::Enum &ref, const Util::StringAtom &attr, TemplateContainer& container){\
        Util::StringAtom enumIdx = xmlReader->GetString(TemplateLoader::IndexAttr.Value());\
        NameSpace::Enum flag = Component::TemplateEnum< NameSpace::Enum >::Value(enumIdx);\
        int value = xmlReader->GetInt(TemplateLoader::ValueAttr.Value());\
        if(value) {\
            ref = (NameSpace::Enum)( ref | flag);\
        } else {\
            ref = (NameSpace::Enum)( ref & (~flag));\
        }
#include "component/template/record/recordflag.h"
    
/// declare load type for struct and class
#undef JTemplateClass
#undef JTemplateStruct
#undef JTemplateValue
#undef JTemplateArray
#undef JTemplateEnumA
#undef JTemplateEnd
#define JTemplateClass(DERIVED, BASE, KIND) \
template<> \
void TemplateLoader::LoadType< Record::DERIVED >(\
    Ptr<IO::XmlReader> &xmlReader, Record::DERIVED &ref, const Util::StringAtom &attr, TemplateContainer& container)
#define JTemplateStruct(DERIVED) \
template<> \
void TemplateLoader::LoadType< Record::DERIVED >(\
Ptr<IO::XmlReader> &xmlReader, Record::DERIVED &ref, const Util::StringAtom &attr, TemplateContainer& container)
#define JTemplateValue(TYPE, NAME)
#define JTemplateArray(TYPE, NAME, SIZE)
#define JTemplateEnumA(TYPE, NAME, ENUM)
#define JTemplateEnd() ; 
#include "component/template/record/recordstruct.h"
#include "component/template/record/recordclass.h"
    
/// load Body for struct and class
#undef JTemplateClass
#undef JTemplateStruct
#undef JTemplateValue
#undef JTemplateArray
#undef JTemplateEnumA
#undef JTemplateEnd
#define JTemplateClass(DERIVED, BASE, KIND) \
    template<> \
bool LoadRecordBody< Record::DERIVED >(Ptr<IO::XmlReader> &xmlReader, const Util::StringAtom& member, const Util::StringAtom& attr,\
    Record::DERIVED &ref, Component::TemplateContainer &container){ \
    typedef BASE RecordBaseClass;\
    if(! attr.IsValid()) {LOGE("xxxxxx"); return false; }
#define JTemplateStruct(DERIVED) \
    template<> \
bool LoadRecordBody< Record::DERIVED >(Ptr<IO::XmlReader> &xmlReader, const Util::StringAtom& member, const Util::StringAtom& attr,\
    Record::DERIVED &ref, Component::TemplateContainer &container){ \
    if(! attr.IsValid()) {LOGE("xxxxxx"); return false; }
#define JTemplateValue(TYPE, NAME)  static Util::StringAtom s_##NAME (#NAME); if( member == s_##NAME ) { \
        TemplateLoader::LoadType< TYPE >(xmlReader, ref.NAME, attr, container); return true; }
#define JTemplateArray(TYPE, NAME, SIZE) static Util::StringAtom s_##NAME (#NAME); if ( member == s_##NAME ) { \
        TYPE elem;\
        TemplateLoader::LoadType< TYPE>(xmlReader, elem, attr, container); ref.NAME.Append(elem); return true; }
#define JTemplateEnumA(TYPE, NAME, ENUM) static Util::StringAtom s_##NAME (#NAME); if (member == s_##NAME ) { \
        Util::StringAtom idxName = xmlReader->GetString(TemplateLoader::IndexAttr.Value());\
        IndexT idx = (IndexT)(Component::TemplateEnum< ENUM >::IndexOf(idxName));\
        TemplateLoader::LoadType< TYPE>(xmlReader, ref.NAME[idx], attr, container); return true; }
#define JTemplateEnd() LOGE("can not find member %s - %s", member.Value(), attr.Value()); return false; }
#include "component/template/record/recordstruct.h"
#undef JTemplateEnd
#define JTemplateEnd() return LoadRecordBody< RecordBaseClass >(xmlReader, member, attr, (RecordBaseClass&)(ref), container); } 
#include "component/template/record/recordclass.h"
    
template<typename TYPE>
void LoadComplexType(Ptr<IO::XmlReader> &xmlReader, TYPE &ref, const Util::StringAtom &attr, TemplateContainer& container){
    // load value from attr
    Util::Array<Util::String> attrs = xmlReader->GetAttrs();
    for (int idx = 0; idx < attrs.Size(); ++idx) {
        Util::StringAtom nodeName = attrs[idx];
        if (nodeName != TemplateLoader::IdAttr && nodeName != TemplateLoader::ParentAttr
               && nodeName != TemplateLoader::ParentAttr && nodeName != TemplateLoader::DefaultAttr
               && nodeName != TemplateLoader::IndexAttr ) {
            LoadRecordBody<TYPE>(xmlReader, nodeName, nodeName, ref, container);
        }
    }
    // load value from body
    if(xmlReader->SetToFirstChild()) do {
        Util::StringAtom nodeName = xmlReader->GetCurrentNodeName();
        LoadRecordBody<TYPE>(xmlReader, nodeName, attr, ref, container);
    } while (xmlReader->SetToNextChild());
}

/// Load Type for struct and class
#undef JTemplateClass
#undef JTemplateStruct
#undef JTemplateValue
#undef JTemplateArray
#undef JTemplateEnumA
#undef JTemplateEnd
#define JTemplateClass(DERIVED, BASE, KIND) \
template<> \
void TemplateLoader::LoadType< Record::DERIVED >(\
Ptr<IO::XmlReader> &xmlReader, Record::DERIVED &ref, const Util::StringAtom &attr, TemplateContainer& container) {\
typedef Record::DERIVED RecordDerivedType;

#define JTemplateStruct(DERIVED) \
template<> \
void TemplateLoader::LoadType< Record::DERIVED >(\
Ptr<IO::XmlReader> &xmlReader, Record::DERIVED &ref, const Util::StringAtom &attr, TemplateContainer& container) {\
typedef Record::DERIVED RecordDerivedType;\
    
#define JTemplateValue(TYPE, NAME)
#define JTemplateArray(TYPE, NAME, SIZE)
#define JTemplateEnumA(TYPE, NAME, ENUM)
#define JTemplateEnd()   LoadComplexType< RecordDerivedType >(xmlReader, ref, attr, container); }
#include "component/template/record/recordstruct.h"
#include "component/template/record/recordclass.h"

template<typename CLASS>
void LoadClass(Ptr<IO::XmlReader> &xmlReader, TemplateLoader::TemplateRecordPtr &ref, TemplateContainer& container){
    LoadRecordHead<CLASS>(xmlReader, ref, container);
    if (ref != NULL) {
        CLASS* classPtr = (CLASS*)(ref);
        LoadComplexType<CLASS>(xmlReader, *classPtr, TemplateLoader::ValueAttr, container);
    }
}
    
/// begin add the entrys
void TemplateLoader::BeginBulkAdd(){
    TemplateLoader::loadEntrys.BeginBulkAdd();
}
    
/// add entrys
void TemplateLoader::Add(const Util::StringAtom& n, LoadClassEntry entry){
    TemplateLoader::loadEntrys.Add(n, entry);
}
    
/// end add entrys
void TemplateLoader::EndBulkAdd(){
    TemplateLoader::loadEntrys.EndBulkAdd();
}
    
/// setup the loader
void TemplateLoader::SetupLoader(){
    ValueAttr = "value";
    IdAttr = "id";
    DefaultAttr = "default";
    ParentAttr = "parent";
    IndexAttr = "index";
    
    BeginBulkAdd();
#undef JTemplateClass
#undef JTemplateStruct
#undef JTemplateValue
#undef JTemplateArray
#undef JTemplateEnumA
#undef JTemplateEnd
#define JTemplateClass(DERIVED, BASE, KIND) \
    Add(Util::StringAtom(#DERIVED), (LoadClassEntry)(& ( LoadClass< Record::DERIVED >) ));
#define JTemplateStruct(DERIVED)
#define JTemplateValue(TYPE, NAME)
#define JTemplateArray(TYPE, NAME, SIZE)
#define JTemplateEnumA(TYPE, NAME, ENUM)
#define JTemplateEnd()
    #include "component/template/record/recordclass.h"
    EndBulkAdd();
}
}