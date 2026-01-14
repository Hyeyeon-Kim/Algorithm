def solution(friends, gifts):
    
    result = {f: {ff : 0 for ff in friends} for f in friends}
    score = {f : 0 for f in friends}
    
    for gift in gifts:
        give, take = gift.split(' ')
        
        result[give][take] += 1
        
        score[give] += 1
        score[take] -= 1
    
    gift = [0 for i in friends]
    
    for i, friend in enumerate(friends):
        for f in friends:
            if f != friend:
                # print(result[friend][f], result[f][friend])
                if result[friend][f] > result[f][friend]:
                    gift[i] += 1
                    # print(1, score[friend], score[f], gift)
                elif result[friend][f] == result[f][friend] and (score[friend] > score[f]):
                    gift[i] += 1
                    # print(2, score[friend], score[f], gift)

    return max(gift)