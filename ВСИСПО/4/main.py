import sys

class Operation:
    def execute(self, a, b):
        raise NotImplementedError


class Sum(Operation):
    def execute(self, a, b):
            result = a + b
            return result


class Sub(Operation):
    def execute(self, a, b):
            result = a - b
            return result
    

class Mul(Operation):
    def execute(self, a, b):
            result = a * b
            return result


class Div(Operation):
    def execute(self, a, b):
            try:
                result = a / b
                return result
            except ZeroDivisionError:
                return "Деление на ноль невозможно"


class DoOp:
    def __init__(self):
         self.sum = Sum()
         self.sub = Sub()
         self.mul = Mul()
         self.div = Div()

    def execute(self, a, b, op):
        ops = ["+", "-", "*", "/"]

        try:
            a = int(a)
            b = int(b)
        except ValueError:
             return "Какое-то из значений не является числом"
        
        op = op
        result = None

        if op not in ops:
            result = "not op"
        else:
            if op == "+":
                result = self.sum.execute(a, b)
            elif op == "-":
                result = self.sub.execute(a, b)
            elif op == "*":
                result = self.mul.execute(a, b)
            elif op == "/":
                result = self.div.execute(a, b)
        
        return result


if __name__ == "__main__":
    ops = ["+", "-", "*", "/"]

    if len(sys.argv) != 4:
         print("Передано слишком мало или много аргументов. Всего принимается три аргумента.")
         
    a = sys.argv[1]
    b = sys.argv[2]
    op = sys.argv[3]
    do_op = DoOp()
    result = do_op.execute(a, b, op)

    if result == "not op":
        print("Введена неверная операция. Допустимые: +, -, *, /")
    else:
        print(f"{a} {op} {b} = {result}")

