args = ['wo', 'hello.c', 'hello2.c']

match args:
    case ['wo']:
        print("只出现了wo")
    case ['wo', file1, *files]:
        print('gcc compile: '+file1+','+','.join(files))
    case['clean']:
        print('clean')
    case _:
        print('invaild command.')
