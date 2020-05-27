# PSU_navy_2019

- **Compilation** make
- **Mark:** 100%

**Groupe Member**
- [@AurelienJoncour](github.com/aurelienjoncour)
- [@SimonRacaud](github.com/simonracaud)

# Subject
Terminal version of a battleship game.
The communication between game is realized with signal USR1 and USR2.
# Usage
```
∼/B-PSU-200> ./navy -h
USAGE
    ./navy [first_player_pid] navy_positions
DESCRIPTION
    first_player_pid: only for the 2nd player. pid of the first player.
    navy_positions: file representing the positions of the ships.
```

**The navy_positions file must be prototyped as follow**

The file must contain 4 boats all of different sizes between 2 and 5  
Each line represent a ship 
(size):(First box):(Last box)

**Example:**

```
2:C4:D4
3:H1:H3
4:E6:H6
5:B1:F1
```

# Preview

![game](https://imgur.com/yzjZ4le.png)

# Bonus

In the bonus, the communication is realized with C socket.
So two players can play the game on two different computers.

- **Compilation** cd bonus; make -C client/ && make -C server/
- **Usage** ./server/navy_server navy_positions
            ./client/navy_client navy_positions server_ip

