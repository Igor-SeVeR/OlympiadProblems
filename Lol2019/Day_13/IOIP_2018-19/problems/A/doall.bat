rem   *** validation ***
call scripts\run-validator-tests.bat
call scripts\run-checker-tests.bat

rem    *** tests ***
md tests
call scripts\gen-input-via-files.bat "..\files\gen.exe 3" "tests\03:tests\04:tests\05:tests\06:tests\07:tests\08:tests\09:tests\10:tests\11:tests\12:tests\13:tests\14:tests\15:tests\16:tests\17:tests\18:tests\19:tests\20:tests\21:tests\22:tests\23:tests\24" "3:4:5:6:7:8:9:10:11:12:13:14:15:16:17:18:19:20:21:22:23:24"
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
call scripts\gen-answer.bat tests\16 tests\16.a "tests" "2"
call scripts\gen-answer.bat tests\17 tests\17.a "tests" "2"
call scripts\gen-answer.bat tests\18 tests\18.a "tests" "2"
call scripts\gen-answer.bat tests\19 tests\19.a "tests" "2"
call scripts\gen-answer.bat tests\20 tests\20.a "tests" "2"
call scripts\gen-answer.bat tests\21 tests\21.a "tests" "2"
call scripts\gen-answer.bat tests\22 tests\22.a "tests" "2"
call scripts\gen-answer.bat tests\23 tests\23.a "tests" "2"
call scripts\gen-answer.bat tests\24 tests\24.a "tests" "2"

