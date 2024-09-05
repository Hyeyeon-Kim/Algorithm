def dfs(visit, node, n_arr, m_arr):
    visit[node] = 1
    result = [node, 0]

    for energy in m_arr:
        for next_node in (node + energy, node - energy):
            if next_node in n_arr and not visit[next_node]:
                child_result = dfs(visit, next_node, n_arr, m_arr)

                result[0] += child_result[1]
                result[1] += max(child_result[0], child_result[1])

    return result

n, m = map(int, input().split())

visit = [0] * 1000001
n_arr = set()
m_arr = []

for _ in range(n):
    n_arr.add(int(input()))

for _ in range(m):
    m_arr.append(int(input()))

root = min(n_arr)
max_energy = dfs(visit, root, n_arr, m_arr)

print(max(max_energy[0], max_energy[1]))
