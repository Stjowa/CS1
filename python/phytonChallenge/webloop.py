import urllib

count = 0
count2 = 0
count3=0
stringf = ""
site = "http://www.pythonchallenge.com/pc/def/linkedlist.php?nothing="
file = ""
string = "12345"
stringlast=""
while (count < 400):
	stringf = urllib.urlopen(site+string)
	print site + string
	file = stringf.read() + ""
	string = ""
	count2=0
	count+=1
	print count
	#temp = file[count2]
	while (count2<len(file)):
		if(file[count2].isdigit()):
			string += file[count2]
		count2+=1
#	if(len(string)==0 and count3==0):
#		string="8022"
#		count3=1
print file
print site + stiring
