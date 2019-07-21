import random
import math
random.seed("personal04/decoding")

class TestGen:
    def __init__(self):
        self.test_number = 0

    def generate_samples(self):
        print('Generating samples...')
        self.print_test("988")
        self.print_test("100905")
        self.print_test("600")

    def generate_hand_tests(self):
        self.print_test("965")
        self.print_test("990")
        self.print_test("777")
        self.print_test("787")
        self.print_test("797")
        self.print_test("878")
        self.print_test("888")
        self.print_test("898")
        self.print_test("978")
        self.print_test("989")
        self.print_test("999")
        self.print_test("108806075101")
        self.print_test("073076908121068")

    def add_digit(self, c, d):
        s = str(c)
        place = random.randint(0, 2)
        if place == 0:
            return f"{d}{s[0]}{s[1]}"
        elif place == 1:
            return f"{s[0]}{d}{s[1]}"
        else:
            return f"{s[0]}{s[1]}{d}"

    def generate_character(self):
        c = random.randint(65, 99)
        while c > 90 and c < 97:
            c = random.randint(65, 99)
        return c

    def generate_incorrect_character(self):
        c = random.randint(10, 99)
        while (c >= 65 and c <= 90) or (c >= 97 and c <= 99):
            c = random.randint(10, 99)
        return c

    def generate_max_tests(self):
        self.print_test('989' * (10**5 // 3))
        self.print_test('999' * (10**5 // 3))
        self.print_test('878' * (10**5 // 3))
        self.print_test('979' * (10**5 // 3))
        self.print_test('969' * (10**5 // 3))
        self.print_test('959' * (10**5 // 3))

    def generate_random_test(self, n):
        pass

    def generate_subtask1(self):
        print('Generating subtask1...')
        self.print_test("100122")
        self.print_test("121122")
        self.print_test("199122")
        self.print_test("919122")
        self.print_test("177122")
        self.print_test("122122122122")
        self.print_test("111111111111")
        self.print_test("111100100111")
        self.print_test("111911111611")
        self.print_test("111511711611")
        self.print_test("111101111811")
        self.print_test("921901181614")
        self.print_test("917901181614")
        for i in range(2):
            s = ''
            for j in range(4):
                if random.randint(1, 2) == 1:
                    s += str(random.randint(100, 122))
                else:
                    s += self.add_digit(self.generate_character(), 1)
            self.print_test(s)

    def generate_subtask2(self):
        print('Generating subtask2...')
        for i in range(15):
            length = random.randint(10, 10**5 // 3)
            s = []
            for i in range(length):
                if random.randint(1, 2) == 1:
                    s.append(str(random.randint(100, 122)))
                else:
                    s.append(self.add_digit(self.generate_character(), 1))
            if random.randint(1, 2) == 1:
                self.print_test(''.join(s))
            else:
                index = random.randint(0, len(s) - 1)
                if random.randint(1, 3) == 1:
                    d = random.randint(0, 9)
                    while d == 1:
                        d = random.randint(0, 9)
                    s[index] = self.add_digit(self.generate_character(), d)
                    while '1' not in s[index]:
                        s[index] = self.add_digit(self.generate_character(), d)
                else:
                    s[index] = self.add_digit(self.generate_incorrect_character(), 1)
                self.print_test(''.join(s))
        self.print_test(''.join([str(random.randint(100, 122)) for _ in range(10**5 // 3)]))

    def generate_subtask3(self):
        print('Generating subtask3...')
        self.generate_hand_tests()
        for i in range(10):
            length = random.randint(10, 1000 // 3)
            d = 0 if i > 7 else random.randint(0, 9)
            s = []
            for i in range(length):
                if random.randint(1, 2) == 1:
                    s.append(str(random.randint(100, 122)))
                else:
                    s.append(self.add_digit(self.generate_character(), d))
            if random.randint(1, 2) == 1:
                self.print_test(''.join(s))
            else:
                index = random.randint(0, len(s) - 1)
                s[index] = self.add_digit(self.generate_incorrect_character(), d)
                self.print_test(''.join(s))
        self.print_test(''.join([str(random.randint(100, 122)) for _ in range(1000 // 3)]))
            
    def generate_subtask4(self):
        print('Generating subtask4...')
        for i in range(15):
            length = random.randint(1000 // 3, 10**5 // 3)
            d = 0 if i > 12 else random.randint(0, 9)
            s = []
            for i in range(length):
                if random.randint(1, 2) == 1:
                    s.append(str(random.randint(100, 122)))
                else:
                    s.append(self.add_digit(self.generate_character(), d))
            if random.randint(1, 2) == 1:
                self.print_test(''.join(s))
            else:
                index = random.randint(0, len(s) - 1)
                s[index] = self.add_digit(self.generate_incorrect_character(), d)
                self.print_test(''.join(s))
        self.print_test(''.join([str(random.randint(100, 122)) for _ in range(10**5 // 3)]))
        self.generate_max_tests()

    def print_test(self, s):
        self.test_number += 1
        print('Generating test #%d' % self.test_number)
        test_name = "{0:0=2d}".format(self.test_number)
        test_file = open(test_name, 'w')
        print(s, file=test_file)
        test_file.close()

    def generate_all_tests(self):
        self.generate_samples()

        self.generate_subtask1()
        self.generate_subtask2()
        self.generate_subtask3()
        self.generate_subtask4()

import time
start = time.time()
writer = TestGen()
writer.generate_all_tests()
finish = time.time()
print('All tests were generated. Elapsed time: ', finish - start)
