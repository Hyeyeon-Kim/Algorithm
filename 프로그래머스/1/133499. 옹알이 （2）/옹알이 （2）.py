def solution(babbling):
    can = ["aya","ye","woo","ma"]
    ans = 0
    
    
    for bal in babbling:
        i = 0
        pre = ""
        can = True
        while (i < len(bal)):
            # print(bal[i:i+3], bal[i:i+2] )
            if (bal[i:i+3] == "aya" and pre != "aya"):
                pre = "aya"
                i += 3
            elif (bal[i:i+2] == "ye"and pre != "ye"):
                pre = "ye"
                i += 2
            elif (bal[i:i+3] == "woo"and pre != "woo"):
                pre = "woo"
                i += 3
            elif (bal[i:i+2] == "ma"and pre != "ma"):
                pre = "ma"
                i += 2
            else:
                can = False
                break
        
        if can:
            ans += 1
    return ans