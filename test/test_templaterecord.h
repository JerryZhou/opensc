#include "component/template/templaterecord.h"

using namespace Record;

TEST(TemplateRecord, type){
    Record::TemplateRecord record;
    EXPECT_EQ(0, record.RecordType);
    
    EXPECT_EQ(0, Record::ERecordType_Invalid);
}
