// 引入逐行读取包
var readline = require('readline');

// 逐行读取接口
var rl = readline.createInterface({
	input: process.stdin,
	output: process.stdout
});

// 当在终端输入一行字符+回车触发line事件，将此行字符串传入函数中作为参数
rl.on('line', function(line) {
	var str = line;
	console.log(checkStr(str))
});

// 检查是否回文
function checkStr(str) {
	var low = 0,
		high = str.length - 1;

	while(low <= high) {
		if(str[low] != str[high]) {
			return false;
		}else {
			low++;
			high--;
		}
	}
	return true;
}
