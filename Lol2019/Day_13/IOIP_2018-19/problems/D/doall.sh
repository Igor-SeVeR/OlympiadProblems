#!/usr/bin/env bash
#   *** validation ***
scripts/run-validator-tests.sh
scripts/run-checker-tests.sh

#    *** tests ***
mkdir -p tests
echo "Generating test #1"
scripts/gen-input-via-stdout.sh "wine files/gen.exe 6 7 5" "tests/01" 1
echo "Generating test #2"
scripts/gen-input-via-stdout.sh "wine files/gen.exe 750 4 871895" "tests/02" 2
echo "Generating test #3"
scripts/gen-input-via-stdout.sh "wine files/gen.exe 375 8 430374" "tests/03" 3
echo "Generating test #4"
scripts/gen-input-via-stdout.sh "wine files/gen.exe 54 54 321560" "tests/04" 4
echo "Generating test #5"
scripts/gen-input-via-stdout.sh "wine files/gen.exe 2 1500 681309" "tests/05" 5
echo "Generating test #6"
scripts/gen-input-via-stdout.sh "wine files/gen.exe 600 5 465956" "tests/06" 6
echo "Generating test #7"
scripts/gen-input-via-stdout.sh "wine files/gen.exe 300 250 827216" "tests/07" 7
echo "Generating test #8"
scripts/gen-input-via-stdout.sh "wine files/gen.exe 300 300 655816" "tests/08" 8
echo "Generating test #9"
scripts/gen-input-via-stdout.sh "wine files/gen.exe 250 300 441501" "tests/09" 9
echo "Generating test #10"
scripts/gen-input-via-stdout.sh "wine files/gen.exe 300 300 682798" "tests/10" 10
echo "Generating test #11"
scripts/gen-input-via-stdout.sh "wine files/gen.exe 239 239 412389" "tests/11" 11
echo "Generating test #12"
scripts/gen-input-via-stdout.sh "wine files/gen.exe 1000000 1 123456" "tests/12" 12
echo "Generating test #13"
scripts/gen-input-via-stdout.sh "wine files/gen.exe 1 1000000 400492" "tests/13" 13
echo "Generating test #14"
scripts/gen-input-via-stdout.sh "wine files/gen.exe 1000000 1 239239" "tests/14" 14
echo "Generating test #15"
scripts/gen-input-via-stdout.sh "wine files/gen.exe 1 1000000 1000000" "tests/15" 15
echo "Generating test #16"
scripts/gen-input-via-stdout.sh "wine files/gen.exe 1000000 1 321123" "tests/16" 16
echo "Generating test #17"
scripts/gen-input-via-stdout.sh "wine files/gen.exe 50000 20 4111" "tests/17" 17
echo "Generating test #18"
scripts/gen-input-via-stdout.sh "wine files/gen.exe 30 33333 5000" "tests/18" 18
echo "Generating test #19"
scripts/gen-input-via-stdout.sh "wine files/gen.exe 4032 248 1234" "tests/19" 19
echo "Generating test #20"
scripts/gen-input-via-stdout.sh "wine files/gen.exe 596 1677 2228" "tests/20" 20
echo "Generating test #21"
scripts/gen-input-via-stdout.sh "wine files/gen.exe 2688 372 1488" "tests/21" 21
echo "Generating test #22"
scripts/gen-input-via-stdout.sh "wine files/gen.exe 1114 897 695418" "tests/22" 22
echo "Generating test #23"
scripts/gen-input-via-stdout.sh "wine files/gen.exe 1522 657 865176" "tests/23" 23
echo "Generating test #24"
scripts/gen-input-via-stdout.sh "wine files/gen.exe 348 2873 639396" "tests/24" 24
echo "Generating test #25"
scripts/gen-input-via-stdout.sh "wine files/gen.exe 1119 893 543812" "tests/25" 25
echo "Generating test #26"
scripts/gen-input-via-stdout.sh "wine files/gen.exe 2032 492 185560" "tests/26" 26
echo "Generating test #27"
scripts/gen-input-via-stdout.sh "wine files/gen.exe 354 2824 642648" "tests/27" 27
echo "Generating test #28"
scripts/gen-input-via-stdout.sh "wine files/gen.exe 1146 872 703816" "tests/28" 28
echo "Generating test #29"
scripts/gen-input-via-stdout.sh "wine files/gen.exe 794 1259 657477" "tests/29" 29
echo "Generating test #30"
scripts/gen-input-via-stdout.sh "wine files/gen.exe 307 3257 68798" "tests/30" 30
echo "Generating test #31"
scripts/gen-input-via-stdout.sh "wine files/gen.exe 1075 930 927434" "tests/31" 31
echo "Generating test #32"
scripts/gen-input-via-stdout.sh "wine files/gen.exe 643 1555 649635" "tests/32" 32
echo "Generating test #33"
scripts/gen-input-via-stdout.sh "wine files/gen.exe 388 2577 930731" "tests/33" 33
echo "Generating test #34"
scripts/gen-input-via-stdout.sh "wine files/gen.exe 8333 120 247381" "tests/34" 34
echo "Generating test #35"
scripts/gen-input-via-stdout.sh "wine files/gen.exe 200 5000 698187" "tests/35" 35
echo "Generating test #36"
scripts/gen-input-via-stdout.sh "wine files/gen.exe 999 1001 879547" "tests/36" 36
echo "Generating test #37"
scripts/gen-input-via-stdout.sh "wine files/gen.exe 902 1108 186556" "tests/37" 37
echo "Generating test #38"
scripts/gen-input-via-stdout.sh "wine files/gen.exe 5208 192 235765" "tests/38" 38
echo "Generating test #39"
scripts/gen-input-via-stdout.sh "wine files/gen.exe 2087 479 696809" "tests/39" 39
echo "Generating test #40"
scripts/gen-input-via-stdout.sh "wine files/gen.exe 1510 662 787019" "tests/40" 40
echo "Generating test #41"
scripts/gen-input-via-stdout.sh "wine files/gen.exe 2785 359 33323" "tests/41" 41
echo "Generating test #42"
scripts/gen-input-via-stdout.sh "wine files/gen.exe 1075 930 695951" "tests/42" 42
echo "Generating test #43"
scripts/gen-input-via-stdout.sh "wine files/gen.exe 1828 547 162526" "tests/43" 43
echo "Generating test #44"
scripts/gen-input-via-stdout.sh "wine files/gen.exe 648 1543 259003" "tests/44" 44
echo "Generating test #45"
scripts/gen-input-via-stdout.sh "wine files/gen.exe 784 1275 992511" "tests/45" 45
echo "Generating test #46"
scripts/gen-input-via-stdout.sh "wine files/gen.exe 481 2079 69844" "tests/46" 46
echo "Generating test #47"
scripts/gen-input-via-stdout.sh "wine files/gen.exe 312 3205 989995" "tests/47" 47
echo "Generating test #48"
scripts/gen-input-via-stdout.sh "wine files/gen.exe 504 1984 407834" "tests/48" 48
echo "Generating test #49"
scripts/gen-input-via-stdout.sh "wine files/gen.exe 193 5181 22477" "tests/49" 49
echo "Generating test #50"
scripts/gen-input-via-stdout.sh "wine files/gen.exe 1000 1000 1000000" "tests/50" 50
echo "Generating test #51"
scripts/gen-input-via-stdout.sh "wine files/gen.exe 10 100000 912929" "tests/51" 51
echo ""
echo "Generating answer for test #1"
scripts/gen-answer.sh tests/01 tests/01.a "tests" "0"
echo ""
echo "Generating answer for test #2"
scripts/gen-answer.sh tests/02 tests/02.a "tests" "1"
echo ""
echo "Generating answer for test #3"
scripts/gen-answer.sh tests/03 tests/03.a "tests" "1"
echo ""
echo "Generating answer for test #4"
scripts/gen-answer.sh tests/04 tests/04.a "tests" "1"
echo ""
echo "Generating answer for test #5"
scripts/gen-answer.sh tests/05 tests/05.a "tests" "1"
echo ""
echo "Generating answer for test #6"
scripts/gen-answer.sh tests/06 tests/06.a "tests" "1"
echo ""
echo "Generating answer for test #7"
scripts/gen-answer.sh tests/07 tests/07.a "tests" "2"
echo ""
echo "Generating answer for test #8"
scripts/gen-answer.sh tests/08 tests/08.a "tests" "2"
echo ""
echo "Generating answer for test #9"
scripts/gen-answer.sh tests/09 tests/09.a "tests" "2"
echo ""
echo "Generating answer for test #10"
scripts/gen-answer.sh tests/10 tests/10.a "tests" "2"
echo ""
echo "Generating answer for test #11"
scripts/gen-answer.sh tests/11 tests/11.a "tests" "2"
echo ""
echo "Generating answer for test #12"
scripts/gen-answer.sh tests/12 tests/12.a "tests" "3"
echo ""
echo "Generating answer for test #13"
scripts/gen-answer.sh tests/13 tests/13.a "tests" "3"
echo ""
echo "Generating answer for test #14"
scripts/gen-answer.sh tests/14 tests/14.a "tests" "3"
echo ""
echo "Generating answer for test #15"
scripts/gen-answer.sh tests/15 tests/15.a "tests" "3"
echo ""
echo "Generating answer for test #16"
scripts/gen-answer.sh tests/16 tests/16.a "tests" "3"
echo ""
echo "Generating answer for test #17"
scripts/gen-answer.sh tests/17 tests/17.a "tests" "4"
echo ""
echo "Generating answer for test #18"
scripts/gen-answer.sh tests/18 tests/18.a "tests" "4"
echo ""
echo "Generating answer for test #19"
scripts/gen-answer.sh tests/19 tests/19.a "tests" "4"
echo ""
echo "Generating answer for test #20"
scripts/gen-answer.sh tests/20 tests/20.a "tests" "4"
echo ""
echo "Generating answer for test #21"
scripts/gen-answer.sh tests/21 tests/21.a "tests" "4"
echo ""
echo "Generating answer for test #22"
scripts/gen-answer.sh tests/22 tests/22.a "tests" "5"
echo ""
echo "Generating answer for test #23"
scripts/gen-answer.sh tests/23 tests/23.a "tests" "5"
echo ""
echo "Generating answer for test #24"
scripts/gen-answer.sh tests/24 tests/24.a "tests" "5"
echo ""
echo "Generating answer for test #25"
scripts/gen-answer.sh tests/25 tests/25.a "tests" "5"
echo ""
echo "Generating answer for test #26"
scripts/gen-answer.sh tests/26 tests/26.a "tests" "5"
echo ""
echo "Generating answer for test #27"
scripts/gen-answer.sh tests/27 tests/27.a "tests" "5"
echo ""
echo "Generating answer for test #28"
scripts/gen-answer.sh tests/28 tests/28.a "tests" "5"
echo ""
echo "Generating answer for test #29"
scripts/gen-answer.sh tests/29 tests/29.a "tests" "5"
echo ""
echo "Generating answer for test #30"
scripts/gen-answer.sh tests/30 tests/30.a "tests" "5"
echo ""
echo "Generating answer for test #31"
scripts/gen-answer.sh tests/31 tests/31.a "tests" "5"
echo ""
echo "Generating answer for test #32"
scripts/gen-answer.sh tests/32 tests/32.a "tests" "5"
echo ""
echo "Generating answer for test #33"
scripts/gen-answer.sh tests/33 tests/33.a "tests" "5"
echo ""
echo "Generating answer for test #34"
scripts/gen-answer.sh tests/34 tests/34.a "tests" "5"
echo ""
echo "Generating answer for test #35"
scripts/gen-answer.sh tests/35 tests/35.a "tests" "5"
echo ""
echo "Generating answer for test #36"
scripts/gen-answer.sh tests/36 tests/36.a "tests" "5"
echo ""
echo "Generating answer for test #37"
scripts/gen-answer.sh tests/37 tests/37.a "tests" "5"
echo ""
echo "Generating answer for test #38"
scripts/gen-answer.sh tests/38 tests/38.a "tests" "5"
echo ""
echo "Generating answer for test #39"
scripts/gen-answer.sh tests/39 tests/39.a "tests" "5"
echo ""
echo "Generating answer for test #40"
scripts/gen-answer.sh tests/40 tests/40.a "tests" "5"
echo ""
echo "Generating answer for test #41"
scripts/gen-answer.sh tests/41 tests/41.a "tests" "5"
echo ""
echo "Generating answer for test #42"
scripts/gen-answer.sh tests/42 tests/42.a "tests" "5"
echo ""
echo "Generating answer for test #43"
scripts/gen-answer.sh tests/43 tests/43.a "tests" "5"
echo ""
echo "Generating answer for test #44"
scripts/gen-answer.sh tests/44 tests/44.a "tests" "5"
echo ""
echo "Generating answer for test #45"
scripts/gen-answer.sh tests/45 tests/45.a "tests" "5"
echo ""
echo "Generating answer for test #46"
scripts/gen-answer.sh tests/46 tests/46.a "tests" "5"
echo ""
echo "Generating answer for test #47"
scripts/gen-answer.sh tests/47 tests/47.a "tests" "5"
echo ""
echo "Generating answer for test #48"
scripts/gen-answer.sh tests/48 tests/48.a "tests" "5"
echo ""
echo "Generating answer for test #49"
scripts/gen-answer.sh tests/49 tests/49.a "tests" "5"
echo ""
echo "Generating answer for test #50"
scripts/gen-answer.sh tests/50 tests/50.a "tests" "5"
echo ""
echo "Generating answer for test #51"
scripts/gen-answer.sh tests/51 tests/51.a "tests" "5"
echo ""

