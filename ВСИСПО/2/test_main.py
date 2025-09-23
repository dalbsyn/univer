from main import check, cyr, num, char

string = 'TeSt СТроКА 34 ГарАЖ!~ GaRaGE'

def test_check():
    result = check(string)
    assert result == 'TeStGaRaGE'

def test_cyr():
    result = cyr(string)
    assert result == ['С', 'Т', 'р', 'о', 'К', 'А', 'Г', 'а', 'р', 'А', 'Ж']

def test_num():
    result = num(string)
    assert result == ['3', '4']

def test_char():
    result = char(string)
    assert result == [' ', ' ', ' ', '!', '~', ' ']