import sys
prod=[]
nt=[]
firsts=[]
follows=[]
def first1(head,body):
	a1=body.split('|')
	i=0
	while (i<len(a1)):
		a2=first(a1[i])
		j=0
		while (j<len(a2)):
			if(a2[j] not in firsts[nt.index(head)])
				firsts[nt.index(head)].append(a2[j])
			j=j+1
		i=i+1
def first(body):
	a1=[]
	if(body=='eps'):
		a1.append('eps')
		return a1
	i=0
	while (i<len(body)):
		if(body[i] not in nt):
			a1.append(body[i])
			break
		else:
			j=nt.index(body[i])
			if('null' in firsts[j]):
				firsts[j].remove('null')
				a2=prod[j].split('->')
				first1(a2[0],a2[1])
			k=0
			check=0
			while(k<len(firsts[j])):
				if(firsts[j][k]=='eps'):
					check=1
				elif(firsts[j][k] not in a1):
					a1.append(firsts[j][k])
				k=k+1
			if(check==0):
				break
			i=i+1
	return a1

def follow(head):
	j=nt.index(head)
	if(j==0):
		follows[j].append('$')
	i=0
	while(i<n):
		a1=prod[i].split('->')
		a2=a1[1].split('|')
		j=0
		while(j<len(a2)):
			if(head in a2[j]):
				k=a2[j].index(head)
				check=0
				if(k<len(a2[j])-1):
					a3=first(a2[j][k+1:])
					l=0
					check=0
					while(l<len(a3)):
						if(a3[l]=='eps'):
							check=1
						elif(a3[l] not in follows[j]):
							follows[j].append(a3[l])
						l=l+1
				if(check==1||k==len(a2[j])-1):
					l=nt.index(a1[0])
					if('null' in follows[l]):
						follows[l].remove('null')
						follow(a1[0])
					m=0
					while(m<len(follows[l])):
						if(follows[l][m] not in follows[j]):
							follows[j].append(follows[l][m])
						m=m+1

sys.stdout.write('Enter no. of productions ')
n=int(raw_input())
i=0
while(i<n):
	sys.stdout.write('Enter production ')
	prod.append(raw_input())
	a1=prod[i].split('->')[0]
	nt.append(a1)
	firsts.append(['null'])
	follows.append(['null'])
	i=i+1
i=0
while(i<n):
	a1=prod[i].split('->')	
	j=nt.index(a1[0])
	if('null' in firsts[j]):
		firsts[j].remove('null')
		first1(a1[0],a1[1])
	i=i+1
i=0
while(i<n):
	a1=prod[i].split('->')	
	j=nt.index(a1[0])
	if('null' in follows[j]):
		follows[j].remove('null')
		follow(a1[0])
	i=i+1

print firsts
print follows
