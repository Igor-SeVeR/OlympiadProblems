rem   *** validation ***
call scripts\run-validator-tests.bat
call scripts\run-checker-tests.bat

rem    *** tests ***
md tests
call scripts\gen-input-via-stdout.bat "files\gen.exe 6 7 5" "tests\01" 1
call scripts\gen-input-via-stdout.bat "files\gen.exe 750 4 871895" "tests\02" 2
call scripts\gen-input-via-stdout.bat "files\gen.exe 375 8 430374" "tests\03" 3
call scripts\gen-input-via-stdout.bat "files\gen.exe 54 54 321560" "tests\04" 4
call scripts\gen-input-via-stdout.bat "files\gen.exe 2 1500 681309" "tests\05" 5
call scripts\gen-input-via-stdout.bat "files\gen.exe 600 5 465956" "tests\06" 6
call scripts\gen-input-via-stdout.bat "files\gen.exe 300 250 827216" "tests\07" 7
call scripts\gen-input-via-stdout.bat "files\gen.exe 300 300 655816" "tests\08" 8
call scripts\gen-input-via-stdout.bat "files\gen.exe 250 300 441501" "tests\09" 9
call scripts\gen-input-via-stdout.bat "files\gen.exe 300 300 682798" "tests\10" 10
call scripts\gen-input-via-stdout.bat "files\gen.exe 239 239 412389" "tests\11" 11
call scripts\gen-input-via-stdout.bat "files\gen.exe 1000000 1 123456" "tests\12" 12
call scripts\gen-input-via-stdout.bat "files\gen.exe 1 1000000 400492" "tests\13" 13
call scripts\gen-input-via-stdout.bat "files\gen.exe 1000000 1 239239" "tests\14" 14
call scripts\gen-input-via-stdout.bat "files\gen.exe 1 1000000 1000000" "tests\15" 15
call scripts\gen-input-via-stdout.bat "files\gen.exe 1000000 1 321123" "tests\16" 16
call scripts\gen-input-via-stdout.bat "files\gen.exe 50000 20 4111" "tests\17" 17
call scripts\gen-input-via-stdout.bat "files\gen.exe 30 33333 5000" "tests\18" 18
call scripts\gen-input-via-stdout.bat "files\gen.exe 4032 248 1234" "tests\19" 19
call scripts\gen-input-via-stdout.bat "files\gen.exe 596 1677 2228" "tests\20" 20
call scripts\gen-input-via-stdout.bat "files\gen.exe 2688 372 1488" "tests\21" 21
call scripts\gen-input-via-stdout.bat "files\gen.exe 1114 897 695418" "tests\22" 22
call scripts\gen-input-via-stdout.bat "files\gen.exe 1522 657 865176" "tests\23" 23
call scripts\gen-input-via-stdout.bat "files\gen.exe 348 2873 639396" "tests\24" 24
call scripts\gen-input-via-stdout.bat "files\gen.exe 1119 893 543812" "tests\25" 25
call scripts\gen-input-via-stdout.bat "files\gen.exe 2032 492 185560" "tests\26" 26
call scripts\gen-input-via-stdout.bat "files\gen.exe 354 2824 642648" "tests\27" 27
call scripts\gen-input-via-stdout.bat "files\gen.exe 1146 872 703816" "tests\28" 28
call scripts\gen-input-via-stdout.bat "files\gen.exe 794 1259 657477" "tests\29" 29
call scripts\gen-input-via-stdout.bat "files\gen.exe 307 3257 68798" "tests\30" 30
call scripts\gen-input-via-stdout.bat "files\gen.exe 1075 930 927434" "tests\31" 31
call scripts\gen-input-via-stdout.bat "files\gen.exe 643 1555 649635" "tests\32" 32
call scripts\gen-input-via-stdout.bat "files\gen.exe 388 2577 930731" "tests\33" 33
call scripts\gen-input-via-stdout.bat "files\gen.exe 8333 120 247381" "tests\34" 34
call scripts\gen-input-via-stdout.bat "files\gen.exe 200 5000 698187" "tests\35" 35
call scripts\gen-input-via-stdout.bat "files\gen.exe 999 1001 879547" "tests\36" 36
call scripts\gen-input-via-stdout.bat "files\gen.exe 902 1108 186556" "tests\37" 37
call scripts\gen-input-via-stdout.bat "files\gen.exe 5208 192 235765" "tests\38" 38
call scripts\gen-input-via-stdout.bat "files\gen.exe 2087 479 696809" "tests\39" 39
call scripts\gen-input-via-stdout.bat "files\gen.exe 1510 662 787019" "tests\40" 40
call scripts\gen-input-via-stdout.bat "files\gen.exe 2785 359 33323" "tests\41" 41
call scripts\gen-input-via-stdout.bat "files\gen.exe 1075 930 695951" "tests\42" 42
call scripts\gen-input-via-stdout.bat "files\gen.exe 1828 547 162526" "tests\43" 43
call scripts\gen-input-via-stdout.bat "files\gen.exe 648 1543 259003" "tests\44" 44
call scripts\gen-input-via-stdout.bat "files\gen.exe 784 1275 992511" "tests\45" 45
call scripts\gen-input-via-stdout.bat "files\gen.exe 481 2079 69844" "tests\46" 46
call scripts\gen-input-via-stdout.bat "files\gen.exe 312 3205 989995" "tests\47" 47
call scripts\gen-input-via-stdout.bat "files\gen.exe 504 1984 407834" "tests\48" 48
call scripts\gen-input-via-stdout.bat "files\gen.exe 193 5181 22477" "tests\49" 49
call scripts\gen-input-via-stdout.bat "files\gen.exe 1000 1000 1000000" "tests\50" 50
call scripts\gen-input-via-stdout.bat "files\gen.exe 10 100000 912929" "tests\51" 51
call scripts\gen-answer.bat tests\01 tests\01.a "tests" "0"
call scripts\gen-answer.bat tests\02 tests\02.a "tests" "1"
call scripts\gen-answer.bat tests\03 tests\03.a "tests" "1"
call scripts\gen-answer.bat tests\04 tests\04.a "tests" "1"
call scripts\gen-answer.bat tests\05 tests\05.a "tests" "1"
call scripts\gen-answer.bat tests\06 tests\06.a "tests" "1"
call scripts\gen-answer.bat tests\07 tests\07.a "tests" "2"
call scripts\gen-answer.bat tests\08 tests\08.a "tests" "2"
call scripts\gen-answer.bat tests\09 tests\09.a "tests" "2"
call scripts\gen-answer.bat tests\10 tests\10.a "tests" "2"
call scripts\gen-answer.bat tests\11 tests\11.a "tests" "2"
call scripts\gen-answer.bat tests\12 tests\12.a "tests" "3"
call scripts\gen-answer.bat tests\13 tests\13.a "tests" "3"
call scripts\gen-answer.bat tests\14 tests\14.a "tests" "3"
call scripts\gen-answer.bat tests\15 tests\15.a "tests" "3"
call scripts\gen-answer.bat tests\16 tests\16.a "tests" "3"
call scripts\gen-answer.bat tests\17 tests\17.a "tests" "4"
call scripts\gen-answer.bat tests\18 tests\18.a "tests" "4"
call scripts\gen-answer.bat tests\19 tests\19.a "tests" "4"
call scripts\gen-answer.bat tests\20 tests\20.a "tests" "4"
call scripts\gen-answer.bat tests\21 tests\21.a "tests" "4"
call scripts\gen-answer.bat tests\22 tests\22.a "tests" "5"
call scripts\gen-answer.bat tests\23 tests\23.a "tests" "5"
call scripts\gen-answer.bat tests\24 tests\24.a "tests" "5"
call scripts\gen-answer.bat tests\25 tests\25.a "tests" "5"
call scripts\gen-answer.bat tests\26 tests\26.a "tests" "5"
call scripts\gen-answer.bat tests\27 tests\27.a "tests" "5"
call scripts\gen-answer.bat tests\28 tests\28.a "tests" "5"
call scripts\gen-answer.bat tests\29 tests\29.a "tests" "5"
call scripts\gen-answer.bat tests\30 tests\30.a "tests" "5"
call scripts\gen-answer.bat tests\31 tests\31.a "tests" "5"
call scripts\gen-answer.bat tests\32 tests\32.a "tests" "5"
call scripts\gen-answer.bat tests\33 tests\33.a "tests" "5"
call scripts\gen-answer.bat tests\34 tests\34.a "tests" "5"
call scripts\gen-answer.bat tests\35 tests\35.a "tests" "5"
call scripts\gen-answer.bat tests\36 tests\36.a "tests" "5"
call scripts\gen-answer.bat tests\37 tests\37.a "tests" "5"
call scripts\gen-answer.bat tests\38 tests\38.a "tests" "5"
call scripts\gen-answer.bat tests\39 tests\39.a "tests" "5"
call scripts\gen-answer.bat tests\40 tests\40.a "tests" "5"
call scripts\gen-answer.bat tests\41 tests\41.a "tests" "5"
call scripts\gen-answer.bat tests\42 tests\42.a "tests" "5"
call scripts\gen-answer.bat tests\43 tests\43.a "tests" "5"
call scripts\gen-answer.bat tests\44 tests\44.a "tests" "5"
call scripts\gen-answer.bat tests\45 tests\45.a "tests" "5"
call scripts\gen-answer.bat tests\46 tests\46.a "tests" "5"
call scripts\gen-answer.bat tests\47 tests\47.a "tests" "5"
call scripts\gen-answer.bat tests\48 tests\48.a "tests" "5"
call scripts\gen-answer.bat tests\49 tests\49.a "tests" "5"
call scripts\gen-answer.bat tests\50 tests\50.a "tests" "5"
call scripts\gen-answer.bat tests\51 tests\51.a "tests" "5"

