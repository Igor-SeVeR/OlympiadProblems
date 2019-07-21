rem   *** validation ***
call scripts\run-validator-tests.bat
call scripts\run-checker-tests.bat

rem    *** tests ***
md tests
call scripts\gen-input-via-stdout.bat "files\gen_random.exe 10 5 3 5 7" "tests\02" 2
call scripts\gen-input-via-stdout.bat "files\gen_random.exe 10 10 5 10 5" "tests\03" 3
call scripts\gen-input-via-stdout.bat "files\gen_random.exe 1000 1000 5 1000 995" "tests\04" 4
call scripts\gen-input-via-stdout.bat "files\gen_random.exe 1000 1000 500 1000 500" "tests\05" 5
call scripts\gen-input-via-stdout.bat "files\gen_random.exe 1000 1000 400 1000 600" "tests\06" 6
call scripts\gen-input-via-stdout.bat "files\gen_random.exe 1000 1000 600 1000 400" "tests\07" 7
call scripts\gen-input-via-stdout.bat "files\gen_random.exe 1000 1000 500 900 500" "tests\08" 8
call scripts\gen-input-via-stdout.bat "files\gen_random.exe 1000 1000 1 1 999" "tests\09" 9
call scripts\gen-input-via-stdout.bat "files\gen_random.exe 1000 1 1 1000 999" "tests\10" 10
call scripts\gen-input-via-stdout.bat "files\gen_random.exe 1000 1 999 1000 1" "tests\11" 11
call scripts\gen-input-via-stdout.bat "files\gen_random.exe 1000 1000 999 1 1" "tests\12" 12
call scripts\gen-input-via-stdout.bat "files\gen_random.exe 999 1000 499 1000 500" "tests\13" 13
call scripts\gen-input-via-stdout.bat "files\gen_random.exe 987 1000 493 1000 494" "tests\14" 14
call scripts\gen-input-via-stdout.bat "files\gen_random2.exe 9 5 2 8ad84e2ab2f9ba925b0f298b8056e24d" "tests\15" 15
call scripts\gen-input-via-stdout.bat "files\gen_random2.exe 10 5 5 752" "tests\16" 16
call scripts\gen-input-via-stdout.bat "files\gen_random2.exe 10 5 5 1735" "tests\17" 17
call scripts\gen-input-via-stdout.bat "files\gen_random2.exe 10 5 5 3417" "tests\18" 18
call scripts\gen-input-via-stdout.bat "files\gen_random2.exe 10 5 5 29018" "tests\19" 19
call scripts\gen-input-via-stdout.bat "files\gen_random2.exe 11 8 4 26507 1110" "tests\20" 20
call scripts\gen-input-via-stdout.bat "files\gen_random2.exe 8 7 3 27968 20942" "tests\21" 21
call scripts\gen-input-via-stdout.bat "files\gen_random.exe 1000 1000 50 1000 50" "tests\22" 22
call scripts\gen-input-via-stdout.bat "files\gen_random.exe 1000 1000 50 1000 10" "tests\23" 23
call scripts\gen-input-via-stdout.bat "files\gen_random.exe 1000 1000 10 1000 50" "tests\24" 24
call scripts\gen-input-via-stdout.bat "files\gen_random.exe 1000000000 100000 500 100000 999999500" "tests\25" 25
call scripts\gen-input-via-stdout.bat "files\gen_random.exe 1000000000 100000 500000000 100000 500000000" "tests\26" 26
call scripts\gen-input-via-stdout.bat "files\gen_random.exe 1000000000 100000 400000000 100000 600000000" "tests\27" 27
call scripts\gen-input-via-stdout.bat "files\gen_random.exe 1000000000 100000 600000000 100000 400000000" "tests\28" 28
call scripts\gen-input-via-stdout.bat "files\gen_random.exe 1000000000 100000 500000000 90000 500000000" "tests\29" 29
call scripts\gen-input-via-stdout.bat "files\gen_random.exe 1000000000 100000 1000000 1 999000000" "tests\30" 30
call scripts\gen-input-via-stdout.bat "files\gen_random.exe 1000000000 100000 1000000 100 999000000" "tests\31" 31
call scripts\gen-input-via-stdout.bat "files\gen_random.exe 1000000000 1 1000000 100000 999000000" "tests\32" 32
call scripts\gen-input-via-stdout.bat "files\gen_random.exe 1000000000 1 999000000 100000 1000000" "tests\33" 33
call scripts\gen-input-via-stdout.bat "files\gen_random.exe 1000000000 100000 999000000 1 1000000" "tests\34" 34
call scripts\gen-input-via-stdout.bat "files\gen_random.exe 1000000000 100000 1000000 100000 1000000" "tests\35" 35
call scripts\gen-input-via-stdout.bat "files\gen_random.exe 1000000000 100000 10000000 100000 10000000" "tests\36" 36
call scripts\gen-input-via-stdout.bat "files\gen_random.exe 1000000000 100000 100000000 100000 100000000" "tests\37" 37
call scripts\gen-input-via-stdout.bat "files\gen_random.exe 1000000000 100000 1000000 100000 10000000" "tests\38" 38
call scripts\gen-input-via-stdout.bat "files\gen_random.exe 1000000000 100000 10000000 100000 1000000" "tests\39" 39
call scripts\gen-answer.bat tests\01 tests\01.a "tests" "0"
call scripts\gen-answer.bat tests\02 tests\02.a "tests" "1"
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
call scripts\gen-answer.bat tests\20 tests\20.a "tests" "1"
call scripts\gen-answer.bat tests\21 tests\21.a "tests" "1"
call scripts\gen-answer.bat tests\22 tests\22.a "tests" "1"
call scripts\gen-answer.bat tests\23 tests\23.a "tests" "1"
call scripts\gen-answer.bat tests\24 tests\24.a "tests" "1"
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
call scripts\gen-answer.bat tests\35 tests\35.a "tests" "2"
call scripts\gen-answer.bat tests\36 tests\36.a "tests" "2"
call scripts\gen-answer.bat tests\37 tests\37.a "tests" "2"
call scripts\gen-answer.bat tests\38 tests\38.a "tests" "2"
call scripts\gen-answer.bat tests\39 tests\39.a "tests" "2"

