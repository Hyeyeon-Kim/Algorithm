class user:
    def __init__(self, name):
        self.name = name
        self.score = 0
        self.plus = []
        self.minus = []

user_idx = []
all_user = []

def find_idx(name):
    if (name not in user_idx):
        user_idx.append(name)
        all_user.append(user(name))
    return user_idx.index(name)

def reco(g, t):
    all_user[t].plus[g] += 1
    all_user[t].score -= 1
    all_user[g].minus[t] += 1  
    all_user[g].score += 1
    
def solution(friends, gifts):
    n = len(friends)
    for friend in friends:
        i = find_idx(friend)
        all_user[i].plus = [0] * n 
        all_user[i].minus = [0] * n 
    
    for gift in gifts:
        give, take = gift.split(' ')
        g = find_idx(give)
        t = find_idx(take)
        reco(g, t)
    
    next = [0] * n 
    i = 0 
    for u in all_user:
        cnt = 0
        for j in range(n):
            if i == j:
                continue
            if all_user[i].minus[j] > all_user[j].minus[i]:
                next[i] += 1
            elif all_user[i].minus[j] == all_user[j].minus[i] and all_user[i].score > all_user[j].score:
                next[i] += 1
        i += 1
    
    return max(next)