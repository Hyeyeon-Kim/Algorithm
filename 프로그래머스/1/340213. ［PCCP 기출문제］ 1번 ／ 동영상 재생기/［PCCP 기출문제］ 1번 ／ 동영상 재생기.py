def change(time):
    h, m = map(int, time.split(':'))
    return h * 60 + m

def re(time):
    h = time // 60
    m = time % 60
    
    
    return str(h).zfill(2) + ':' + str(m).zfill(2)

def solution(video_len, pos, op_start, op_end, commands):
    video_len = change(video_len)
    pos = change(pos)
    op_start = change(op_start)
    op_end = change(op_end)
    
    for c in commands:
        if op_start <= pos <= op_end:
            pos = op_end
        
        if c == 'next':
            pos += 10
            if pos > video_len:
                pos = video_len
        else:
            pos -= 10
            if pos < 0:
                pos = 0
        
        if op_start <= pos <= op_end:
            pos = op_end
            
    return re(pos)