def solution(data, ext, val_ext, sort_by):
    idx = {"code":0, "date":1, "maximum":2, "remain":3}
    
    data = [d for d in data if d[idx[ext]] < val_ext]
    
    return sorted(data, key=lambda x:x[idx[sort_by]])