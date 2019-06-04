import random

def task13(cards):
	shake=random.randint(2,len(cards)-2)
	part1=cards[:shake]
	#print('part 1',part1)
	part2=cards[shake:]
	#print('part 2', part2)
	place = random.randint(0, len(part1) - 1)
	#print('place', place)
	return part1[:place] + part2 + part1[place:]

def test(n):
	cards = [0,1,2,3,4,5,6,7,8,9,10]
	print('Deck:', cards)
	for i in range(n):
		cards = task13(cards)
		print('Mixed', i+1, cards)