class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        row_hash_map = defaultdict(set)
        col_hash_map = defaultdict(set)
        square_hash_map = defaultdict(set)

        for i in range(9):
            for j in range(9):
                if (board[i][j] in row_hash_map[i]
                    or board [j][i] in col_hash_map[i]
                    or board[i][j] in square_hash_map[(i // 3, j // 3)]): 
                    return False

                if board[i][j] != ".": 
                    row_hash_map[i].add(board[i][j])
                    square_hash_map[(i // 3, j // 3)].add(board[i][j])
                if board[j][i] != ".": col_hash_map[i].add(board[j][i])
    
        return True