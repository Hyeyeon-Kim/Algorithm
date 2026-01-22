def change(t):
    t = list(map(int, t.split(':')))
    return t[0] * 60 + t[1]

def solution(video_len, pos, op_start, op_end, commands):
    video_len = change(video_len)
    pos = change(pos)
    op_start = change(op_start)
    op_end = change(op_end)
    
    for c in commands:
        if op_start <= pos <= op_end:
            pos = op_end
        
        if c == "next":
            pos += 10
            if pos > video_len:
                pos = video_len
        elif c == "prev":
            pos -= 10
            if pos < 0:
                pos = 0
        
    if op_start <= pos <= op_end:
        pos = op_end

    return str(pos//60).zfill(2) + ':' + str(pos%60).zfill(2)