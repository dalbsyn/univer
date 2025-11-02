from main import Sum, Div, Mul, Sub, DoOp

def test_sum():
    s = Sum()
    assert s.execute(2, 3) == 5
    assert s.execute(-1, 1) == 0
    print("Sum(): прошел тесты")

def test_sub():
    s = Sub()
    assert s.execute(5, 3) == 2
    assert s.execute(0, 1) == -1
    print("Sub(): прошел тесты")

def test_mul():
    m = Mul()
    assert m.execute(2, 4) == 8
    assert m.execute(-2, 3) == -6
    print("Mul(): прошел тесты")

def test_div():
    d = Div()
    assert d.execute(6, 2) == 3
    assert d.execute(9, 3) == 3
    print("Div(): прошел тесты")

def test_do_op():
    d = DoOp()
    assert d.execute(2, 3, "+") == 5
    assert d.execute(4, 2, "-") == 2
    assert d.execute(3, 3, "*") == 9
    assert d.execute(8, 4, "/") == 2
    assert d.execute(2, 3, "^") == "not op"
    print("DoOp(): прошел тесты")

# Заглушки для тестирования DoOp без применения реальных функций
class StubSum:
    def execute(self, a, b):
        return "stub_sum"

class StubSub:
    def execute(self, a, b):
        return "stub_sub"

class StubMul:
    def execute(self, a, b):
        return "stub_mul"

class StubDiv:
    def execute(self, a, b):
        return "stub_div"


class DoOpStub:
    def __init__(self):
        self.sum = StubSum()
        self.sub = StubSub()
        self.mul = StubMul()
        self.div = StubDiv()

    def execute(self, a, b, op):
        ops = ["+", "-", "*", "/"]
        if op not in ops:
            return "not op"
        if op == "+": 
            return self.sum.execute(a, b)
        if op == "-":
            return self.sub.execute(a, b)
        if op == "*":
            return self.mul.execute(a, b)
        if op == "/":
            return self.div.execute(a, b)


def test_do_op_stub():
    calc = DoOpStub()
    assert calc.execute(1, 2, "+") == "stub_sum"
    assert calc.execute(1, 2, "-") == "stub_sub"
    assert calc.execute(1, 2, "*") == "stub_mul"
    assert calc.execute(1, 2, "/") == "stub_div"
    assert calc.execute(1, 2, "^") == "not op"
    print("DoOp() c заглушками: прошел тесты")

if __name__ == "__main__":
    test_sum()
    test_sub()
    test_mul()
    test_div()
    test_do_op()
    test_do_op_stub()
    print("Все тесты пройдены.")
