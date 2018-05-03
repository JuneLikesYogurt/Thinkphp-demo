<?php if (!defined('THINK_PATH')) exit();?><!DOCTYPE html>
<html>
<head>
	<title>Index</title>
	<style type="text/css">
		#daohang{
			height: 100px;
			background: #abcdef;
		}
		a{
			border: 1px solid gray;
			font-size: 60px;
			text-decoration: none;
		}
	</style>
</head>
<body>
	<div id="daohang">
		<?php if(is_array($list)): foreach($list as $key=>$v): ?><a href="__APP__/City/<?php echo ($v["name"]); ?>"><?php echo ($v["name"]); ?></a><?php endforeach; endif; ?>
	</div>

	<h1>欢迎你访问上海的网页</h1>
</body>
</html>