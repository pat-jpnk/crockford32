#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "../../src/Crockford32.h"
#include <iostream>


TEST_CASE("encode testing") {
  CHECK(encode("Airplane435Kmsss", true) == "85MQ4W3CC5Q6AD1K6N5PTWVKECP");
  CHECK(encode("Airplane435Kmsss", false) == "85MQ4W3CC5Q6AD1K6N5PTWVKEC");
  CHECK(encode("UUJDANJDDD", true) == "ANAMMH219S548H24E");
  CHECK(encode("laudantium", true) == "DHGQAS31DST6JXBD4");
  CHECK(encode("aldnakdjnadkjawnw382928892ixBHHJBAJHBAWDAHWDD", true) == "C5P68VK1DDJ6MVK1CHNPMRBQDSVK6E1J74S3GE1S69MQGGJ891544GAA91142NT48545EH24D");
  CHECK(encode("Architecte", false) == "85S66T39EHJP6X35");
  CHECK(encode("blueOcean4everblueHello", true) == "C9P7ASAFCDJP2VHMCNV6AWK2DHTPAJ35DHP6Y8");
  CHECK(encode("Achteruitkijkspiegel", true) == "85HPGX35E9TPJX3BD5N6PWVGD5JPESBCW");
  CHECK(encode("DurgerdamHolyslootNoorderstrookOostNoorderstrookHolyslootNoorderstrookOostNoorderstrookWestRansdorpHolyslootNoorderstrookOost",true) == "8HTQ4SV5E9J62VA8DXP7JWVCDXQQ8KKFDXS68SBJEDT74VVFDD7PYWVM9SQPYWK4CNS76X3JDXQPPJ3FDHWQ6V3FDXT4WVVFE9J6AWKKEHS6YVVB9XQQ6X2EDXQQ4S35E9SQ8WKFDXNNESBKEH962VKKCHQQ4W28DXP7JWVCDXQQ8KKFDXS68SBJEDT74VVFDD7PYWVMJ");
  CHECK(encode("&#&##*&#(((HJBDAHDBAHDBAJDBDBADB", true) == "4RHJC8S358K26A185144MGJ485448GJ191244GAA8H148GJ18H105");
  CHECK(encode("Hello123!!!siaodnadand(???", true) == "91JPRV3F64S3689145SPJRBFCHQ62S31DSJ2GFSZ7WP");

}


TEST_CASE("decode testing") {
  CHECK(decode("C9P7AS80", true) == "blue");
  CHECK(decode("50N5AA1A4DAJGJJ48574MH248GC", true) == "(*U(*#U(JDANJDDD");
  CHECK(decode("50N5AA1A4DAJGJJ48574MH248G", false) == "(*U(*#U(JDANJDDD");
  CHECK(decode("C5P68VK17DNP8TKEC5J2WTVAC5VPWXSA6CW34E9J71SQ6WVKEDSQ6WVKCHJ68S34CHJ68V", true) == "aldna;kdjnad.kjawnw*382928sssssssssdddddddd");
  CHECK(decode("C5P68VK17DNP8TKEC5J2WTVAC5VPWXSA6CW34E9J71SQ6WVKEDSQ6WVKCHJ68S34CHJ68", false) == "aldna;kdjnad.kjawnw*382928sssssssssdddddddd");
  CHECK(decode("6GS36DSJ6MSK2D1Q6GT3GC9N64S30C9N6WTK6U", true) == "42372531474481512015753");
  CHECK(decode("60WK6C1Q70T3GC1P6RRK8DSH6GS36CHK70RKE", false) == "09307848066147142323817");
  CHECK(decode("ADGPWKB9CXTPAV34CN0PRV35DSJ6A$", true) == "SanMigueldeAllende");
}

// TODO: tests covering all cases

TEST_CASE("decode input validation testing") {
  CHECK(validate_decode_input("0123456789ABCDEFGHJKMNPQRSTVWXYZ*", true) == true);
  CHECK(validate_decode_input("MMPQSfLi", true) == false);
  CHECK(validate_decode_input("CQ4=", true) == true);
  CHECK(validate_decode_input("889I2QVZ", false) == false);
  CHECK(validate_decode_input("8892QVZ=", false) == false);
  CHECK(validate_decode_input("WVZY2423110", true) == true);
  CHECK(validate_decode_input("MDE3219VQ", false) == true);  
  CHECK(validate_decode_input("RSSTVZ421=*", true) == false);
}


TEST_CASE("create checksum testing") {
  CHECK(create_checksum("MintTeaisNice") == 'M');
  CHECK(create_checksum("dandkjandkajndajknda.kjdnadjnadknd.adnadnajanxljanxak.jxan") == 'D');
  CHECK(create_checksum("4892742843923472934827948729247289493921") == '=');
  CHECK(create_checksum("TreeBeeSeeWeGleeMe") == 'V');
  CHECK(create_checksum("Llanfairpwllgwyngyll") == '8');
  CHECK(create_checksum("Bolshezingereyevo") == 'N');
}


TEST_CASE("validate checksum testing") {
  CHECK(validate_checksum("LalalaMedicalMagicalBridge", '~') == true);
  CHECK(validate_checksum("LalalaMedicalMagicalBridge", '*') == false);
  CHECK(validate_checksum("248234204923840920402420", 'U') == true);
  CHECK(validate_checksum("neemcontactmetmijop", 'W') == true);
  CHECK(validate_checksum("adnadjnadk;jandjandakjdnakjdnak.jdnakj.dnad.", 'W') == true);
  CHECK(validate_checksum("adnadjnadk;jandjandakjdnakjdnak.jdnakj.dnad.", '=') == false);
}