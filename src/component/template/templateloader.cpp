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
    
/// load head of class
template<typename TYPE>
void LoadRecordHead(Ptr<IO::XmlReader> &xmlReader, TemplateLoader::TemplateRecordPtr &ref, Component::TemplateContainer &container){
    TYPE * data = new TYPE();
    if(xmlReader->HasAttr("parent")) {
        Util::StringAtom parent = xmlReader->GetString("parent");
        const Record::TemplateRecord * recordParent = container.FindRecord(parent, (Record::ERecordType)(data->RecordType));
        if(recordParent) {
            TYPE *parntDerived = (TYPE*)(recordParent);
            *data = *parntDerived;
        }
    }
    
    if (xmlReader->HasAttr("id")) {
        Util::StringAtom id = xmlReader->GetString("id");
        data->Id = id;
        ref = data;
        return;
    }
    
    delete data;
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