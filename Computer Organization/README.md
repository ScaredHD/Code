# Q&As
## 数据通路 (Datapath)
### 当数据通路执行存数指令时, 控制信号 `MemRead` 为什么不能为无关项?

<img src="./images/datapath1.png" width=50% alt="MIPS datapath">
<img src="./images/datapath2.png" width=50% alt="control signals">

问题描述: `regWrite` 为 `0`, `MemRead` 为任何值, 都不会对寄存器造成影响.

**解答**:
[Single cycle mips, store word(sw) control values, why MemRead is 0 and not “don't care”?](https://stackoverflow.com/questions/52710955/single-cycle-mips-store-wordsw-control-values-why-memread-is-0-and-not-don)