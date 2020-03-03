class Solution:
    def buddyStrings(self, A: str, B: str) -> bool:
        a = []
        b = []
        if(len(A)!=len(B)) or (len(A)==1):
            return False
        elif A==B and len(set(A))!=len(A):
            return True
        else:
            for i,j in zip(A,B):
                if i!=j:
                    a.append(i)
                    b.append(j)
            b.reverse()
            return len(a)==2 and a==b
