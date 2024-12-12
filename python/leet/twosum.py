def twoSum(self,nums, target):
    resul=[]
    for i in nums:
        for j in nums:
            if(i+j == target):
                resul.append(i.index())
                resul.append(j.index())
    return(resul)
        
print(twoSum(0,[2,7,11,15],9))