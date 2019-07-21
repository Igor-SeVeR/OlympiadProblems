rem   *** validation ***
call scripts\run-validator-tests.bat
call scripts\run-checker-tests.bat

rem    *** tests ***
md tests
call scripts\gen-input-via-stdout.bat "py -3 files\gen_rand.pys3 1 0 409671054" "tests\03" 3
call scripts\gen-input-via-stdout.bat "py -3 files\gen_rand.pys3 2 0 357695701" "tests\04" 4
call scripts\gen-input-via-stdout.bat "py -3 files\gen_rand.pys3 7 0 345256212" "tests\05" 5
call scripts\gen-input-via-stdout.bat "py -3 files\gen_rand.pys3 7 1 395349629" "tests\06" 6
call scripts\gen-input-via-stdout.bat "py -3 files\gen_rand.pys3 7 2 827593364" "tests\07" 7
call scripts\gen-input-via-stdout.bat "py -3 files\gen_bamboo.pys3 7 0 707062158" "tests\08" 8
call scripts\gen-input-via-stdout.bat "py -3 files\gen_bamboo.pys3 7 1 918939911" "tests\09" 9
call scripts\gen-input-via-stdout.bat "py -3 files\gen_bamboo.pys3 7 2 621582928" "tests\10" 10
call scripts\gen-input-via-stdout.bat "py -3 files\gen_binary.pys3 7 0 606460871" "tests\11" 11
call scripts\gen-input-via-stdout.bat "py -3 files\gen_binary.pys3 7 1 483269769" "tests\12" 12
call scripts\gen-input-via-stdout.bat "py -3 files\gen_binary.pys3 7 2 556774048" "tests\13" 13
call scripts\gen-input-via-stdout.bat "py -3 files\gen_brush.pys3 7 0 948290898" "tests\14" 14
call scripts\gen-input-via-stdout.bat "py -3 files\gen_brush.pys3 7 1 422038612" "tests\15" 15
call scripts\gen-input-via-stdout.bat "py -3 files\gen_brush.pys3 7 2 308824404" "tests\16" 16
call scripts\gen-input-via-stdout.bat "py -3 files\gen_sun.pys3 7 0 134739307" "tests\17" 17
call scripts\gen-input-via-stdout.bat "py -3 files\gen_sun.pys3 7 1 826757108" "tests\18" 18
call scripts\gen-input-via-stdout.bat "py -3 files\gen_sun.pys3 7 2 97264187" "tests\19" 19
call scripts\gen-input-via-stdout.bat "py -3 files\gen_rand.pys3 15 0 496865763" "tests\20" 20
call scripts\gen-input-via-stdout.bat "py -3 files\gen_rand.pys3 15 1 13236992" "tests\21" 21
call scripts\gen-input-via-stdout.bat "py -3 files\gen_rand.pys3 15 2 684780101" "tests\22" 22
call scripts\gen-input-via-stdout.bat "py -3 files\gen_bamboo.pys3 15 0 599140183" "tests\23" 23
call scripts\gen-input-via-stdout.bat "py -3 files\gen_bamboo.pys3 15 1 630303066" "tests\24" 24
call scripts\gen-input-via-stdout.bat "py -3 files\gen_bamboo.pys3 15 2 168347296" "tests\25" 25
call scripts\gen-input-via-stdout.bat "py -3 files\gen_binary.pys3 15 0 282376942" "tests\26" 26
call scripts\gen-input-via-stdout.bat "py -3 files\gen_binary.pys3 15 1 421194960" "tests\27" 27
call scripts\gen-input-via-stdout.bat "py -3 files\gen_binary.pys3 15 2 626242845" "tests\28" 28
call scripts\gen-input-via-stdout.bat "py -3 files\gen_brush.pys3 15 0 147770407" "tests\29" 29
call scripts\gen-input-via-stdout.bat "py -3 files\gen_brush.pys3 15 1 575105198" "tests\30" 30
call scripts\gen-input-via-stdout.bat "py -3 files\gen_brush.pys3 15 2 122241929" "tests\31" 31
call scripts\gen-input-via-stdout.bat "py -3 files\gen_sun.pys3 15 0 329150354" "tests\32" 32
call scripts\gen-input-via-stdout.bat "py -3 files\gen_sun.pys3 15 1 82374312" "tests\33" 33
call scripts\gen-input-via-stdout.bat "py -3 files\gen_sun.pys3 15 2 782758096" "tests\34" 34
call scripts\gen-input-via-stdout.bat "py -3 files\gen_rand.pys3 80 0 411957232" "tests\35" 35
call scripts\gen-input-via-stdout.bat "py -3 files\gen_rand.pys3 80 1 145937598" "tests\36" 36
call scripts\gen-input-via-stdout.bat "py -3 files\gen_rand.pys3 80 2 103482049" "tests\37" 37
call scripts\gen-input-via-stdout.bat "py -3 files\gen_bamboo.pys3 80 0 954374451" "tests\38" 38
call scripts\gen-input-via-stdout.bat "py -3 files\gen_bamboo.pys3 80 1 452687711" "tests\39" 39
call scripts\gen-input-via-stdout.bat "py -3 files\gen_bamboo.pys3 80 2 239651772" "tests\40" 40
call scripts\gen-input-via-stdout.bat "py -3 files\gen_binary.pys3 80 0 822044433" "tests\41" 41
call scripts\gen-input-via-stdout.bat "py -3 files\gen_binary.pys3 80 1 243404443" "tests\42" 42
call scripts\gen-input-via-stdout.bat "py -3 files\gen_binary.pys3 80 2 804455478" "tests\43" 43
call scripts\gen-input-via-stdout.bat "py -3 files\gen_brush.pys3 80 0 21293793" "tests\44" 44
call scripts\gen-input-via-stdout.bat "py -3 files\gen_brush.pys3 80 1 601992739" "tests\45" 45
call scripts\gen-input-via-stdout.bat "py -3 files\gen_brush.pys3 80 2 208892938" "tests\46" 46
call scripts\gen-input-via-stdout.bat "py -3 files\gen_sun.pys3 80 0 450290807" "tests\47" 47
call scripts\gen-input-via-stdout.bat "py -3 files\gen_sun.pys3 80 1 678746276" "tests\48" 48
call scripts\gen-input-via-stdout.bat "py -3 files\gen_sun.pys3 80 2 472015824" "tests\49" 49
call scripts\gen-input-via-stdout.bat "py -3 files\gen_rand.pys3 400 0 522430927" "tests\50" 50
call scripts\gen-input-via-stdout.bat "py -3 files\gen_rand.pys3 400 1 244861438" "tests\51" 51
call scripts\gen-input-via-stdout.bat "py -3 files\gen_rand.pys3 400 2 307814499" "tests\52" 52
call scripts\gen-input-via-stdout.bat "py -3 files\gen_bamboo.pys3 400 0 184669931" "tests\53" 53
call scripts\gen-input-via-stdout.bat "py -3 files\gen_bamboo.pys3 400 1 878269106" "tests\54" 54
call scripts\gen-input-via-stdout.bat "py -3 files\gen_bamboo.pys3 400 2 702428432" "tests\55" 55
call scripts\gen-input-via-stdout.bat "py -3 files\gen_binary.pys3 400 0 733375473" "tests\56" 56
call scripts\gen-input-via-stdout.bat "py -3 files\gen_binary.pys3 400 1 637288049" "tests\57" 57
call scripts\gen-input-via-stdout.bat "py -3 files\gen_binary.pys3 400 2 546212386" "tests\58" 58
call scripts\gen-input-via-stdout.bat "py -3 files\gen_brush.pys3 400 0 991795830" "tests\59" 59
call scripts\gen-input-via-stdout.bat "py -3 files\gen_brush.pys3 400 1 770955245" "tests\60" 60
call scripts\gen-input-via-stdout.bat "py -3 files\gen_brush.pys3 400 2 134788965" "tests\61" 61
call scripts\gen-input-via-stdout.bat "py -3 files\gen_sun.pys3 400 0 613746867" "tests\62" 62
call scripts\gen-input-via-stdout.bat "py -3 files\gen_sun.pys3 400 1 638331488" "tests\63" 63
call scripts\gen-input-via-stdout.bat "py -3 files\gen_sun.pys3 400 2 288986596" "tests\64" 64
call scripts\gen-input-via-stdout.bat "py -3 files\gen_rand.pys3 3000 0 479281451" "tests\65" 65
call scripts\gen-input-via-stdout.bat "py -3 files\gen_rand.pys3 3000 1 578029308" "tests\66" 66
call scripts\gen-input-via-stdout.bat "py -3 files\gen_rand.pys3 3000 2 677523468" "tests\67" 67
call scripts\gen-input-via-stdout.bat "py -3 files\gen_bamboo.pys3 3000 0 892083127" "tests\68" 68
call scripts\gen-input-via-stdout.bat "py -3 files\gen_bamboo.pys3 3000 1 751692736" "tests\69" 69
call scripts\gen-input-via-stdout.bat "py -3 files\gen_bamboo.pys3 3000 2 94480116" "tests\70" 70
call scripts\gen-input-via-stdout.bat "py -3 files\gen_binary.pys3 3000 0 291508449" "tests\71" 71
call scripts\gen-input-via-stdout.bat "py -3 files\gen_binary.pys3 3000 1 266037095" "tests\72" 72
call scripts\gen-input-via-stdout.bat "py -3 files\gen_binary.pys3 3000 2 80044308" "tests\73" 73
call scripts\gen-input-via-stdout.bat "py -3 files\gen_brush.pys3 3000 0 785369768" "tests\74" 74
call scripts\gen-input-via-stdout.bat "py -3 files\gen_brush.pys3 3000 1 798770992" "tests\75" 75
call scripts\gen-input-via-stdout.bat "py -3 files\gen_brush.pys3 3000 2 302741373" "tests\76" 76
call scripts\gen-input-via-stdout.bat "py -3 files\gen_sun.pys3 3000 0 568262124" "tests\77" 77
call scripts\gen-input-via-stdout.bat "py -3 files\gen_sun.pys3 3000 1 739206059" "tests\78" 78
call scripts\gen-input-via-stdout.bat "py -3 files\gen_sun.pys3 3000 2 309917193" "tests\79" 79
call scripts\gen-answer.bat tests\01 tests\01.a "tests" "0"
call scripts\gen-answer.bat tests\02 tests\02.a "tests" "0"
call scripts\gen-answer.bat tests\03 tests\03.a "tests" "1"
call scripts\gen-answer.bat tests\04 tests\04.a "tests" "1"
call scripts\gen-answer.bat tests\05 tests\05.a "tests" "1"
call scripts\gen-answer.bat tests\06 tests\06.a "tests" "1"
call scripts\gen-answer.bat tests\07 tests\07.a "tests" "1"
call scripts\gen-answer.bat tests\08 tests\08.a "tests" "1"
call scripts\gen-answer.bat tests\09 tests\09.a "tests" "1"
call scripts\gen-answer.bat tests\10 tests\10.a "tests" "1"
call scripts\gen-answer.bat tests\11 tests\11.a "tests" "1"
call scripts\gen-answer.bat tests\12 tests\12.a "tests" "1"
call scripts\gen-answer.bat tests\13 tests\13.a "tests" "1"
call scripts\gen-answer.bat tests\14 tests\14.a "tests" "1"
call scripts\gen-answer.bat tests\15 tests\15.a "tests" "1"
call scripts\gen-answer.bat tests\16 tests\16.a "tests" "1"
call scripts\gen-answer.bat tests\17 tests\17.a "tests" "1"
call scripts\gen-answer.bat tests\18 tests\18.a "tests" "1"
call scripts\gen-answer.bat tests\19 tests\19.a "tests" "1"
call scripts\gen-answer.bat tests\20 tests\20.a "tests" "2"
call scripts\gen-answer.bat tests\21 tests\21.a "tests" "2"
call scripts\gen-answer.bat tests\22 tests\22.a "tests" "2"
call scripts\gen-answer.bat tests\23 tests\23.a "tests" "2"
call scripts\gen-answer.bat tests\24 tests\24.a "tests" "2"
call scripts\gen-answer.bat tests\25 tests\25.a "tests" "2"
call scripts\gen-answer.bat tests\26 tests\26.a "tests" "2"
call scripts\gen-answer.bat tests\27 tests\27.a "tests" "2"
call scripts\gen-answer.bat tests\28 tests\28.a "tests" "2"
call scripts\gen-answer.bat tests\29 tests\29.a "tests" "2"
call scripts\gen-answer.bat tests\30 tests\30.a "tests" "2"
call scripts\gen-answer.bat tests\31 tests\31.a "tests" "2"
call scripts\gen-answer.bat tests\32 tests\32.a "tests" "2"
call scripts\gen-answer.bat tests\33 tests\33.a "tests" "2"
call scripts\gen-answer.bat tests\34 tests\34.a "tests" "2"
call scripts\gen-answer.bat tests\35 tests\35.a "tests" "3"
call scripts\gen-answer.bat tests\36 tests\36.a "tests" "3"
call scripts\gen-answer.bat tests\37 tests\37.a "tests" "3"
call scripts\gen-answer.bat tests\38 tests\38.a "tests" "3"
call scripts\gen-answer.bat tests\39 tests\39.a "tests" "3"
call scripts\gen-answer.bat tests\40 tests\40.a "tests" "3"
call scripts\gen-answer.bat tests\41 tests\41.a "tests" "3"
call scripts\gen-answer.bat tests\42 tests\42.a "tests" "3"
call scripts\gen-answer.bat tests\43 tests\43.a "tests" "3"
call scripts\gen-answer.bat tests\44 tests\44.a "tests" "3"
call scripts\gen-answer.bat tests\45 tests\45.a "tests" "3"
call scripts\gen-answer.bat tests\46 tests\46.a "tests" "3"
call scripts\gen-answer.bat tests\47 tests\47.a "tests" "3"
call scripts\gen-answer.bat tests\48 tests\48.a "tests" "3"
call scripts\gen-answer.bat tests\49 tests\49.a "tests" "3"
call scripts\gen-answer.bat tests\50 tests\50.a "tests" "4"
call scripts\gen-answer.bat tests\51 tests\51.a "tests" "4"
call scripts\gen-answer.bat tests\52 tests\52.a "tests" "4"
call scripts\gen-answer.bat tests\53 tests\53.a "tests" "4"
call scripts\gen-answer.bat tests\54 tests\54.a "tests" "4"
call scripts\gen-answer.bat tests\55 tests\55.a "tests" "4"
call scripts\gen-answer.bat tests\56 tests\56.a "tests" "4"
call scripts\gen-answer.bat tests\57 tests\57.a "tests" "4"
call scripts\gen-answer.bat tests\58 tests\58.a "tests" "4"
call scripts\gen-answer.bat tests\59 tests\59.a "tests" "4"
call scripts\gen-answer.bat tests\60 tests\60.a "tests" "4"
call scripts\gen-answer.bat tests\61 tests\61.a "tests" "4"
call scripts\gen-answer.bat tests\62 tests\62.a "tests" "4"
call scripts\gen-answer.bat tests\63 tests\63.a "tests" "4"
call scripts\gen-answer.bat tests\64 tests\64.a "tests" "4"
call scripts\gen-answer.bat tests\65 tests\65.a "tests" "5"
call scripts\gen-answer.bat tests\66 tests\66.a "tests" "5"
call scripts\gen-answer.bat tests\67 tests\67.a "tests" "5"
call scripts\gen-answer.bat tests\68 tests\68.a "tests" "5"
call scripts\gen-answer.bat tests\69 tests\69.a "tests" "5"
call scripts\gen-answer.bat tests\70 tests\70.a "tests" "5"
call scripts\gen-answer.bat tests\71 tests\71.a "tests" "5"
call scripts\gen-answer.bat tests\72 tests\72.a "tests" "5"
call scripts\gen-answer.bat tests\73 tests\73.a "tests" "5"
call scripts\gen-answer.bat tests\74 tests\74.a "tests" "5"
call scripts\gen-answer.bat tests\75 tests\75.a "tests" "5"
call scripts\gen-answer.bat tests\76 tests\76.a "tests" "5"
call scripts\gen-answer.bat tests\77 tests\77.a "tests" "5"
call scripts\gen-answer.bat tests\78 tests\78.a "tests" "5"
call scripts\gen-answer.bat tests\79 tests\79.a "tests" "5"

