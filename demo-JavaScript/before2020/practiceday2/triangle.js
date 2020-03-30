// 引入逐行读取包
var readline = require('readline');

// 逐行读取接口
var rl = readline.createInterface({
	input: process.stdin,
	output: process.stdout
});

rl.setPrompt('input>');
rl.prompt();

// 当在终端输入一行字符+回车触发line事件，将此行字符串传入函数中作为参数
rl.on('line', function(line) {
	var str = line;
	console.log(check(str));
});


function check (str) {
	var num = new Array(3);
	num = str.split(" ",3);
	//！！！！！！！！用Number()函数将字符串转化为数值
	var a = Number(num[0]),b = Number(num[1]),c = Number(num[2]);

	if((a + b > c)&&(a + c > b)&&(b + c > a)){
		return true;
	}else {
		return false;
	}
}
