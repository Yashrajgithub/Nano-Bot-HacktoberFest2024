board = [["0", "1", "2"], ["3", "4", "5"], ["6", "7", "8"]]
def print_board():
    for row in board:
        print(row)
def check_game(mark):
    for i in range(3):
        if board[i][0] == mark and board[i][1] == mark and board[i][2] == mark:
            return True
    for i in range(3):
        if board[0][i] == mark and board[1][i] == mark and board[2][i] == mark:
            return True
    if board[0][0] == mark and board[1][1] == mark and board[2][2] == mark:
        return True
    elif board[0][2] == mark and board[1][1] == mark and board[2][0] == mark:
        return True
    return False
def play_TTT():
    print_board()
    current_player = "player 1"
    mark = "X"
    moves = 0
    result = False
    while moves < 9:
        print(current_player + " move.")
        print("Enter cell no.")
        cell = int(input())
        row = cell // 3
        col = cell % 3
        if board[row][col] == "X" or board[row][col] == "O":
            print("Occupied!!, Try another one.")
            print_board()
            continue
        else:
            board[row][col] = mark
            moves += 1
            print_board()
        if check_game(mark):
            print(current_player + " has won !!!")
            break
        if moves == 9:
            print("Draw")
            break
        if current_player == "player 1":
            current_player = "player 2"
            mark = "O"
        else:
            current_player = "player 1"
            mark = "X"
play_TTT()
