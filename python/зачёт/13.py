import random

def task_13(cards):
    print('Карты -',cards)
    i=0
    shake=random.randint(2,len(cards)-2)
    part1=cards[:shake]
    part2=cards[shake:]
    print('Колода первая -',part1)
    print('Колода вторая -',part2)
    print('---------------------------')
    place = random.randint(0, len(part1) - 1)
    return part1[:place]+part2+part1[place:]

def test():
    cards = [0,1,2,3,4,5,6,7,8,9,10]
    print('Колода:', cards)
    for i in range(10):
        cards=task_13(cards)
        print('Перемешивание', i+1, cards)
        print('---------------------------')
