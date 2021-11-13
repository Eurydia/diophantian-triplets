from math import sqrt

def type_guard(q):
    while True:
        try:
            ans =  int(input(q))
            return ans
        except ValueError:
            print('Please enter a valid value.')


def from_one_side(a: int, limit: int):
    for b in range(limit+1):
        if a > b:
            c = sqrt((a * a) - (b * b))
        else:
            c = sqrt((b * b) - (a * a))
        
        if not c.is_integer():
            c = sqrt((a * a) + (b * b))
        
        if c.is_integer() and b > c and (a + c) > b:
            print(*map(int, sorted((a, b, c))), sep=', ')

def from_two_sides(a: int, b: int):
    if a > b:
        c = sqrt((a * a) - (b * b))
    else:
        c = sqrt((b * b) - (a * a))
    
    if not c.is_integer():
        c = sqrt((a * a) + (b * b))
    
    if c.is_integer():
        print(*map(int, sorted((a, b, c))), sep=', ')

def  from_three_sides(a: int, b: int, c: int):
    a, b, c = sorted((a, b, c))
    if (a + b) > c and c == sqrt((a * a) + (b * b)):
        print('\n{O}These are indeed sides of a pythagorean triangle.{O}')
    else:
        print('\n{X}These are indeed NOT sides of a pythagorean triangle.{X}')
         
def main():
    while True:
        print("\nPick a function...")
        print("\tFunction (1): Find all possible triplets from one known side length.")
        print("\tFunction (2): Find the third side length from 2 known sides.")
        print("\tFunction (3): Check if a triplets of numbers are sides of a pythagorian triangle.")
        print("\tFunction (4): About this program.")
        print("\tFunction (5): Exit program.")

        switch_choice =  type_guard("\n\tLet's go with >> ")
        if 3 >= switch_choice >= 1:
            print('\nNOTE: Select { -1 } in any field to go back to function selection screen.\n')

        if switch_choice == 1:
            print('Enter your known side length')
            known_lenght = type_guard('\tKnown side length >> ')
            
            if known_lenght != -1:
                print('Enter the limiting size of side lengths')
                limiting_lenght = type_guard('\tLenght to not exceed >> ')
             
                if limiting_lenght != -1:
                    print('\nAll possible triplet(s) generated from your known side length')
                    from_one_side(known_lenght, limiting_lenght)
                    print('-'*15)

        elif switch_choice == 2:
            print('Enter your known side length')
            known_lenght = type_guard('\tKnown side length >> ')
            
            if known_lenght != -1:
                print('Enter your other known side length')
                known_lenght2 = type_guard('\tOther known side length >> ')
             
                if known_lenght2 != -1:
                    print('\nTriplet generated from your known side lengths')
                    from_two_sides(known_lenght, known_lenght2)
                    print('-'*15)
        
        elif switch_choice == 3:
            print('Enter your known side length')
            known_lenght = type_guard('\tKnown side length >> ')
            
            if known_lenght != -1:
                print('Enter your other known side length')
                known_lenght2 = type_guard('\tOther known side length >> ')
             
                if known_lenght2 != -1:
                    print('Enter your other other known side length')
                    known_lenght3 = type_guard('\tOther other known side length >> ')
             
                    if known_lenght3 != -1:
                        from_three_sides(known_lenght, known_lenght2, known_lenght3)
                        print('-'*15)

        elif switch_choice == 4:
            print("\nNotes from the developer...")
            print("\t>>\tThis program is designed to only work with positive integers.")
            print("\t>>\tIn Function { 1 } and { 2 }, this program will NOT output decimal side lengths.")
            print("\t\tOnly integers.")
            print("\t>>\tAny floating point number given as an input will be rounded down.")
            print("\t>>\tSide lengths given to this program do not need to be in an order!")
            print("\t>>\tNo, characters are not valid inputs.")

        else:       
            break
        
if __name__ == '__main__':
    main()