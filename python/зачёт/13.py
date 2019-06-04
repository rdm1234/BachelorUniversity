import random
# Вариант 1
def task13(cards,count):
	print('Карты -',cards)
	count1=0
	i=0
	shake=random.randint(2,len(cards))
	parts=random.randint(1,2)
	if(parts==1):
		column1=cards[:len(cards)//shake]
		column2=cards[len(cards)//shake:]
	else:
		column1=cards[len(cards)//shake:]
		column2=cards[:len(cards)//shake]
	print('Колода первая -',column1)
	print('Колода вторая -',column2)
	print('---------------------------')
	j=len(column1)%random.randint(1,len(column1))
	print('j -',j)
	while(count1!=count):
		column1.insert(j,column2[i])
		i=i+1
		j=j+1
		if(i==len(column2)):
			cards=column1
			shake=random.randint(1,len(cards))
			parts=random.randint(1,2)
			if(parts==1):
				column1=cards[:len(cards)//shake]
				column2=cards[len(cards)//shake:]
			else:
				column1=cards[len(cards)//shake:]
				column2=cards[:len(cards)//shake]
			print('Колода первая -',column1)
			print('Колода вторая -',column2)
			print('j -',j)
			j=len(column1)%random.randint(1,len(column1))
			i=0
			print('Полученная колода -',cards)
			count1=count1+1

# Вариант 2
def task13_2(cards):
	shake=random.randint(2,len(cards)-2)
	part1=cards[:shake]
	#print(part1)
	part2=cards[shake:]
	#print(part2)
	place = random.randint(0, len(part1) - 1)
	return part1[:place] + part2 + part1[place:]

def test():
	cards = [0,1,2,3,4,5,6,7,8,9,10]
	print('Deck:', cards)
	for i in range(5):
		cards = task13_2(cards)
		print('Mixed', i+1, cards)
