try:
    x = input('x: ')
    n = input('n: ')
    x=int(x)
    n=int(n)
    if x < 0 or x > 999:
        print('Error : x must be in [0..999]')
    elif n < 1 or n > 100:
        print('Error : n must be in [0..100]')
    else:
        print(f'The power n of x is {x ** n}')
except ValueError:
    print('Error: Please enter a numeric argument')
