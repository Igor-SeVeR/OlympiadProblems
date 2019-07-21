#!/usr/bin/env bash
#   *** validation ***
scripts/run-validator-tests.sh
scripts/run-checker-tests.sh

#    *** tests ***
mkdir -p tests
echo "Generating test #3"
scripts/gen-input-via-stdout.sh "python3 files/gen_rand.pys3 1 0 409671054" "tests/03" 3
echo "Generating test #4"
scripts/gen-input-via-stdout.sh "python3 files/gen_rand.pys3 2 0 357695701" "tests/04" 4
echo "Generating test #5"
scripts/gen-input-via-stdout.sh "python3 files/gen_rand.pys3 7 0 345256212" "tests/05" 5
echo "Generating test #6"
scripts/gen-input-via-stdout.sh "python3 files/gen_rand.pys3 7 1 395349629" "tests/06" 6
echo "Generating test #7"
scripts/gen-input-via-stdout.sh "python3 files/gen_rand.pys3 7 2 827593364" "tests/07" 7
echo "Generating test #8"
scripts/gen-input-via-stdout.sh "python3 files/gen_bamboo.pys3 7 0 707062158" "tests/08" 8
echo "Generating test #9"
scripts/gen-input-via-stdout.sh "python3 files/gen_bamboo.pys3 7 1 918939911" "tests/09" 9
echo "Generating test #10"
scripts/gen-input-via-stdout.sh "python3 files/gen_bamboo.pys3 7 2 621582928" "tests/10" 10
echo "Generating test #11"
scripts/gen-input-via-stdout.sh "python3 files/gen_binary.pys3 7 0 606460871" "tests/11" 11
echo "Generating test #12"
scripts/gen-input-via-stdout.sh "python3 files/gen_binary.pys3 7 1 483269769" "tests/12" 12
echo "Generating test #13"
scripts/gen-input-via-stdout.sh "python3 files/gen_binary.pys3 7 2 556774048" "tests/13" 13
echo "Generating test #14"
scripts/gen-input-via-stdout.sh "python3 files/gen_brush.pys3 7 0 948290898" "tests/14" 14
echo "Generating test #15"
scripts/gen-input-via-stdout.sh "python3 files/gen_brush.pys3 7 1 422038612" "tests/15" 15
echo "Generating test #16"
scripts/gen-input-via-stdout.sh "python3 files/gen_brush.pys3 7 2 308824404" "tests/16" 16
echo "Generating test #17"
scripts/gen-input-via-stdout.sh "python3 files/gen_sun.pys3 7 0 134739307" "tests/17" 17
echo "Generating test #18"
scripts/gen-input-via-stdout.sh "python3 files/gen_sun.pys3 7 1 826757108" "tests/18" 18
echo "Generating test #19"
scripts/gen-input-via-stdout.sh "python3 files/gen_sun.pys3 7 2 97264187" "tests/19" 19
echo "Generating test #20"
scripts/gen-input-via-stdout.sh "python3 files/gen_rand.pys3 15 0 496865763" "tests/20" 20
echo "Generating test #21"
scripts/gen-input-via-stdout.sh "python3 files/gen_rand.pys3 15 1 13236992" "tests/21" 21
echo "Generating test #22"
scripts/gen-input-via-stdout.sh "python3 files/gen_rand.pys3 15 2 684780101" "tests/22" 22
echo "Generating test #23"
scripts/gen-input-via-stdout.sh "python3 files/gen_bamboo.pys3 15 0 599140183" "tests/23" 23
echo "Generating test #24"
scripts/gen-input-via-stdout.sh "python3 files/gen_bamboo.pys3 15 1 630303066" "tests/24" 24
echo "Generating test #25"
scripts/gen-input-via-stdout.sh "python3 files/gen_bamboo.pys3 15 2 168347296" "tests/25" 25
echo "Generating test #26"
scripts/gen-input-via-stdout.sh "python3 files/gen_binary.pys3 15 0 282376942" "tests/26" 26
echo "Generating test #27"
scripts/gen-input-via-stdout.sh "python3 files/gen_binary.pys3 15 1 421194960" "tests/27" 27
echo "Generating test #28"
scripts/gen-input-via-stdout.sh "python3 files/gen_binary.pys3 15 2 626242845" "tests/28" 28
echo "Generating test #29"
scripts/gen-input-via-stdout.sh "python3 files/gen_brush.pys3 15 0 147770407" "tests/29" 29
echo "Generating test #30"
scripts/gen-input-via-stdout.sh "python3 files/gen_brush.pys3 15 1 575105198" "tests/30" 30
echo "Generating test #31"
scripts/gen-input-via-stdout.sh "python3 files/gen_brush.pys3 15 2 122241929" "tests/31" 31
echo "Generating test #32"
scripts/gen-input-via-stdout.sh "python3 files/gen_sun.pys3 15 0 329150354" "tests/32" 32
echo "Generating test #33"
scripts/gen-input-via-stdout.sh "python3 files/gen_sun.pys3 15 1 82374312" "tests/33" 33
echo "Generating test #34"
scripts/gen-input-via-stdout.sh "python3 files/gen_sun.pys3 15 2 782758096" "tests/34" 34
echo "Generating test #35"
scripts/gen-input-via-stdout.sh "python3 files/gen_rand.pys3 80 0 411957232" "tests/35" 35
echo "Generating test #36"
scripts/gen-input-via-stdout.sh "python3 files/gen_rand.pys3 80 1 145937598" "tests/36" 36
echo "Generating test #37"
scripts/gen-input-via-stdout.sh "python3 files/gen_rand.pys3 80 2 103482049" "tests/37" 37
echo "Generating test #38"
scripts/gen-input-via-stdout.sh "python3 files/gen_bamboo.pys3 80 0 954374451" "tests/38" 38
echo "Generating test #39"
scripts/gen-input-via-stdout.sh "python3 files/gen_bamboo.pys3 80 1 452687711" "tests/39" 39
echo "Generating test #40"
scripts/gen-input-via-stdout.sh "python3 files/gen_bamboo.pys3 80 2 239651772" "tests/40" 40
echo "Generating test #41"
scripts/gen-input-via-stdout.sh "python3 files/gen_binary.pys3 80 0 822044433" "tests/41" 41
echo "Generating test #42"
scripts/gen-input-via-stdout.sh "python3 files/gen_binary.pys3 80 1 243404443" "tests/42" 42
echo "Generating test #43"
scripts/gen-input-via-stdout.sh "python3 files/gen_binary.pys3 80 2 804455478" "tests/43" 43
echo "Generating test #44"
scripts/gen-input-via-stdout.sh "python3 files/gen_brush.pys3 80 0 21293793" "tests/44" 44
echo "Generating test #45"
scripts/gen-input-via-stdout.sh "python3 files/gen_brush.pys3 80 1 601992739" "tests/45" 45
echo "Generating test #46"
scripts/gen-input-via-stdout.sh "python3 files/gen_brush.pys3 80 2 208892938" "tests/46" 46
echo "Generating test #47"
scripts/gen-input-via-stdout.sh "python3 files/gen_sun.pys3 80 0 450290807" "tests/47" 47
echo "Generating test #48"
scripts/gen-input-via-stdout.sh "python3 files/gen_sun.pys3 80 1 678746276" "tests/48" 48
echo "Generating test #49"
scripts/gen-input-via-stdout.sh "python3 files/gen_sun.pys3 80 2 472015824" "tests/49" 49
echo "Generating test #50"
scripts/gen-input-via-stdout.sh "python3 files/gen_rand.pys3 400 0 522430927" "tests/50" 50
echo "Generating test #51"
scripts/gen-input-via-stdout.sh "python3 files/gen_rand.pys3 400 1 244861438" "tests/51" 51
echo "Generating test #52"
scripts/gen-input-via-stdout.sh "python3 files/gen_rand.pys3 400 2 307814499" "tests/52" 52
echo "Generating test #53"
scripts/gen-input-via-stdout.sh "python3 files/gen_bamboo.pys3 400 0 184669931" "tests/53" 53
echo "Generating test #54"
scripts/gen-input-via-stdout.sh "python3 files/gen_bamboo.pys3 400 1 878269106" "tests/54" 54
echo "Generating test #55"
scripts/gen-input-via-stdout.sh "python3 files/gen_bamboo.pys3 400 2 702428432" "tests/55" 55
echo "Generating test #56"
scripts/gen-input-via-stdout.sh "python3 files/gen_binary.pys3 400 0 733375473" "tests/56" 56
echo "Generating test #57"
scripts/gen-input-via-stdout.sh "python3 files/gen_binary.pys3 400 1 637288049" "tests/57" 57
echo "Generating test #58"
scripts/gen-input-via-stdout.sh "python3 files/gen_binary.pys3 400 2 546212386" "tests/58" 58
echo "Generating test #59"
scripts/gen-input-via-stdout.sh "python3 files/gen_brush.pys3 400 0 991795830" "tests/59" 59
echo "Generating test #60"
scripts/gen-input-via-stdout.sh "python3 files/gen_brush.pys3 400 1 770955245" "tests/60" 60
echo "Generating test #61"
scripts/gen-input-via-stdout.sh "python3 files/gen_brush.pys3 400 2 134788965" "tests/61" 61
echo "Generating test #62"
scripts/gen-input-via-stdout.sh "python3 files/gen_sun.pys3 400 0 613746867" "tests/62" 62
echo "Generating test #63"
scripts/gen-input-via-stdout.sh "python3 files/gen_sun.pys3 400 1 638331488" "tests/63" 63
echo "Generating test #64"
scripts/gen-input-via-stdout.sh "python3 files/gen_sun.pys3 400 2 288986596" "tests/64" 64
echo "Generating test #65"
scripts/gen-input-via-stdout.sh "python3 files/gen_rand.pys3 3000 0 479281451" "tests/65" 65
echo "Generating test #66"
scripts/gen-input-via-stdout.sh "python3 files/gen_rand.pys3 3000 1 578029308" "tests/66" 66
echo "Generating test #67"
scripts/gen-input-via-stdout.sh "python3 files/gen_rand.pys3 3000 2 677523468" "tests/67" 67
echo "Generating test #68"
scripts/gen-input-via-stdout.sh "python3 files/gen_bamboo.pys3 3000 0 892083127" "tests/68" 68
echo "Generating test #69"
scripts/gen-input-via-stdout.sh "python3 files/gen_bamboo.pys3 3000 1 751692736" "tests/69" 69
echo "Generating test #70"
scripts/gen-input-via-stdout.sh "python3 files/gen_bamboo.pys3 3000 2 94480116" "tests/70" 70
echo "Generating test #71"
scripts/gen-input-via-stdout.sh "python3 files/gen_binary.pys3 3000 0 291508449" "tests/71" 71
echo "Generating test #72"
scripts/gen-input-via-stdout.sh "python3 files/gen_binary.pys3 3000 1 266037095" "tests/72" 72
echo "Generating test #73"
scripts/gen-input-via-stdout.sh "python3 files/gen_binary.pys3 3000 2 80044308" "tests/73" 73
echo "Generating test #74"
scripts/gen-input-via-stdout.sh "python3 files/gen_brush.pys3 3000 0 785369768" "tests/74" 74
echo "Generating test #75"
scripts/gen-input-via-stdout.sh "python3 files/gen_brush.pys3 3000 1 798770992" "tests/75" 75
echo "Generating test #76"
scripts/gen-input-via-stdout.sh "python3 files/gen_brush.pys3 3000 2 302741373" "tests/76" 76
echo "Generating test #77"
scripts/gen-input-via-stdout.sh "python3 files/gen_sun.pys3 3000 0 568262124" "tests/77" 77
echo "Generating test #78"
scripts/gen-input-via-stdout.sh "python3 files/gen_sun.pys3 3000 1 739206059" "tests/78" 78
echo "Generating test #79"
scripts/gen-input-via-stdout.sh "python3 files/gen_sun.pys3 3000 2 309917193" "tests/79" 79
echo ""
echo "Generating answer for test #1"
scripts/gen-answer.sh tests/01 tests/01.a "tests" "0"
echo ""
echo "Generating answer for test #2"
scripts/gen-answer.sh tests/02 tests/02.a "tests" "0"
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
scripts/gen-answer.sh tests/07 tests/07.a "tests" "1"
echo ""
echo "Generating answer for test #8"
scripts/gen-answer.sh tests/08 tests/08.a "tests" "1"
echo ""
echo "Generating answer for test #9"
scripts/gen-answer.sh tests/09 tests/09.a "tests" "1"
echo ""
echo "Generating answer for test #10"
scripts/gen-answer.sh tests/10 tests/10.a "tests" "1"
echo ""
echo "Generating answer for test #11"
scripts/gen-answer.sh tests/11 tests/11.a "tests" "1"
echo ""
echo "Generating answer for test #12"
scripts/gen-answer.sh tests/12 tests/12.a "tests" "1"
echo ""
echo "Generating answer for test #13"
scripts/gen-answer.sh tests/13 tests/13.a "tests" "1"
echo ""
echo "Generating answer for test #14"
scripts/gen-answer.sh tests/14 tests/14.a "tests" "1"
echo ""
echo "Generating answer for test #15"
scripts/gen-answer.sh tests/15 tests/15.a "tests" "1"
echo ""
echo "Generating answer for test #16"
scripts/gen-answer.sh tests/16 tests/16.a "tests" "1"
echo ""
echo "Generating answer for test #17"
scripts/gen-answer.sh tests/17 tests/17.a "tests" "1"
echo ""
echo "Generating answer for test #18"
scripts/gen-answer.sh tests/18 tests/18.a "tests" "1"
echo ""
echo "Generating answer for test #19"
scripts/gen-answer.sh tests/19 tests/19.a "tests" "1"
echo ""
echo "Generating answer for test #20"
scripts/gen-answer.sh tests/20 tests/20.a "tests" "2"
echo ""
echo "Generating answer for test #21"
scripts/gen-answer.sh tests/21 tests/21.a "tests" "2"
echo ""
echo "Generating answer for test #22"
scripts/gen-answer.sh tests/22 tests/22.a "tests" "2"
echo ""
echo "Generating answer for test #23"
scripts/gen-answer.sh tests/23 tests/23.a "tests" "2"
echo ""
echo "Generating answer for test #24"
scripts/gen-answer.sh tests/24 tests/24.a "tests" "2"
echo ""
echo "Generating answer for test #25"
scripts/gen-answer.sh tests/25 tests/25.a "tests" "2"
echo ""
echo "Generating answer for test #26"
scripts/gen-answer.sh tests/26 tests/26.a "tests" "2"
echo ""
echo "Generating answer for test #27"
scripts/gen-answer.sh tests/27 tests/27.a "tests" "2"
echo ""
echo "Generating answer for test #28"
scripts/gen-answer.sh tests/28 tests/28.a "tests" "2"
echo ""
echo "Generating answer for test #29"
scripts/gen-answer.sh tests/29 tests/29.a "tests" "2"
echo ""
echo "Generating answer for test #30"
scripts/gen-answer.sh tests/30 tests/30.a "tests" "2"
echo ""
echo "Generating answer for test #31"
scripts/gen-answer.sh tests/31 tests/31.a "tests" "2"
echo ""
echo "Generating answer for test #32"
scripts/gen-answer.sh tests/32 tests/32.a "tests" "2"
echo ""
echo "Generating answer for test #33"
scripts/gen-answer.sh tests/33 tests/33.a "tests" "2"
echo ""
echo "Generating answer for test #34"
scripts/gen-answer.sh tests/34 tests/34.a "tests" "2"
echo ""
echo "Generating answer for test #35"
scripts/gen-answer.sh tests/35 tests/35.a "tests" "3"
echo ""
echo "Generating answer for test #36"
scripts/gen-answer.sh tests/36 tests/36.a "tests" "3"
echo ""
echo "Generating answer for test #37"
scripts/gen-answer.sh tests/37 tests/37.a "tests" "3"
echo ""
echo "Generating answer for test #38"
scripts/gen-answer.sh tests/38 tests/38.a "tests" "3"
echo ""
echo "Generating answer for test #39"
scripts/gen-answer.sh tests/39 tests/39.a "tests" "3"
echo ""
echo "Generating answer for test #40"
scripts/gen-answer.sh tests/40 tests/40.a "tests" "3"
echo ""
echo "Generating answer for test #41"
scripts/gen-answer.sh tests/41 tests/41.a "tests" "3"
echo ""
echo "Generating answer for test #42"
scripts/gen-answer.sh tests/42 tests/42.a "tests" "3"
echo ""
echo "Generating answer for test #43"
scripts/gen-answer.sh tests/43 tests/43.a "tests" "3"
echo ""
echo "Generating answer for test #44"
scripts/gen-answer.sh tests/44 tests/44.a "tests" "3"
echo ""
echo "Generating answer for test #45"
scripts/gen-answer.sh tests/45 tests/45.a "tests" "3"
echo ""
echo "Generating answer for test #46"
scripts/gen-answer.sh tests/46 tests/46.a "tests" "3"
echo ""
echo "Generating answer for test #47"
scripts/gen-answer.sh tests/47 tests/47.a "tests" "3"
echo ""
echo "Generating answer for test #48"
scripts/gen-answer.sh tests/48 tests/48.a "tests" "3"
echo ""
echo "Generating answer for test #49"
scripts/gen-answer.sh tests/49 tests/49.a "tests" "3"
echo ""
echo "Generating answer for test #50"
scripts/gen-answer.sh tests/50 tests/50.a "tests" "4"
echo ""
echo "Generating answer for test #51"
scripts/gen-answer.sh tests/51 tests/51.a "tests" "4"
echo ""
echo "Generating answer for test #52"
scripts/gen-answer.sh tests/52 tests/52.a "tests" "4"
echo ""
echo "Generating answer for test #53"
scripts/gen-answer.sh tests/53 tests/53.a "tests" "4"
echo ""
echo "Generating answer for test #54"
scripts/gen-answer.sh tests/54 tests/54.a "tests" "4"
echo ""
echo "Generating answer for test #55"
scripts/gen-answer.sh tests/55 tests/55.a "tests" "4"
echo ""
echo "Generating answer for test #56"
scripts/gen-answer.sh tests/56 tests/56.a "tests" "4"
echo ""
echo "Generating answer for test #57"
scripts/gen-answer.sh tests/57 tests/57.a "tests" "4"
echo ""
echo "Generating answer for test #58"
scripts/gen-answer.sh tests/58 tests/58.a "tests" "4"
echo ""
echo "Generating answer for test #59"
scripts/gen-answer.sh tests/59 tests/59.a "tests" "4"
echo ""
echo "Generating answer for test #60"
scripts/gen-answer.sh tests/60 tests/60.a "tests" "4"
echo ""
echo "Generating answer for test #61"
scripts/gen-answer.sh tests/61 tests/61.a "tests" "4"
echo ""
echo "Generating answer for test #62"
scripts/gen-answer.sh tests/62 tests/62.a "tests" "4"
echo ""
echo "Generating answer for test #63"
scripts/gen-answer.sh tests/63 tests/63.a "tests" "4"
echo ""
echo "Generating answer for test #64"
scripts/gen-answer.sh tests/64 tests/64.a "tests" "4"
echo ""
echo "Generating answer for test #65"
scripts/gen-answer.sh tests/65 tests/65.a "tests" "5"
echo ""
echo "Generating answer for test #66"
scripts/gen-answer.sh tests/66 tests/66.a "tests" "5"
echo ""
echo "Generating answer for test #67"
scripts/gen-answer.sh tests/67 tests/67.a "tests" "5"
echo ""
echo "Generating answer for test #68"
scripts/gen-answer.sh tests/68 tests/68.a "tests" "5"
echo ""
echo "Generating answer for test #69"
scripts/gen-answer.sh tests/69 tests/69.a "tests" "5"
echo ""
echo "Generating answer for test #70"
scripts/gen-answer.sh tests/70 tests/70.a "tests" "5"
echo ""
echo "Generating answer for test #71"
scripts/gen-answer.sh tests/71 tests/71.a "tests" "5"
echo ""
echo "Generating answer for test #72"
scripts/gen-answer.sh tests/72 tests/72.a "tests" "5"
echo ""
echo "Generating answer for test #73"
scripts/gen-answer.sh tests/73 tests/73.a "tests" "5"
echo ""
echo "Generating answer for test #74"
scripts/gen-answer.sh tests/74 tests/74.a "tests" "5"
echo ""
echo "Generating answer for test #75"
scripts/gen-answer.sh tests/75 tests/75.a "tests" "5"
echo ""
echo "Generating answer for test #76"
scripts/gen-answer.sh tests/76 tests/76.a "tests" "5"
echo ""
echo "Generating answer for test #77"
scripts/gen-answer.sh tests/77 tests/77.a "tests" "5"
echo ""
echo "Generating answer for test #78"
scripts/gen-answer.sh tests/78 tests/78.a "tests" "5"
echo ""
echo "Generating answer for test #79"
scripts/gen-answer.sh tests/79 tests/79.a "tests" "5"
echo ""

