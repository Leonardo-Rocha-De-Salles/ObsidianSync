
| Present state | 00  | 01 B  | 10   | 11 D | output: | 00  | 01  | 10  | 11  |
| ------------- | --- | ----- | ---- | ---- | ------- | --- | --- | --- | --- |
| b             | ba  | X     | X    | X    |         | 0   | 1   | 1   | 1   |
| ba            | X   | X     | X    | bad  |         |     | 1   | 1   |     |
| bad           | X   | X     | badc | X    |         |     |     |     |     |
| badc          | X   | badcb | X    | bad  |         |     |     |     |     |
| badcb         |     |       |      |      |         |     |     |     |     |
| badcba        |     |       |      |      |         |     |     |     |     |
| badcbac       |     |       |      |      |         |     |     |     |     |
|               |     |       |      |      |         |     |     |     |     |
|               |     |       |      |      |         |     |     |     |     |
