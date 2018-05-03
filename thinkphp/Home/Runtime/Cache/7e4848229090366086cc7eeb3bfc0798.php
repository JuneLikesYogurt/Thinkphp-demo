<?php if (!defined('THINK_PATH')) exit();?><!DOCTYPE html>
<html>
<head>
	<title>index</title>
	<!-- <style type="text/css">
		p{
			background: pink;
		}
	</style> -->
	<link rel="stylesheet" type="text/css" href="__PUBLIC__/css/basic.css"/>
	<script type="text/javascript" src='__PUBLIC__/Js/basic.js'></script>
</head>
<body>
    <!--  <p>hello, <?php echo ($name); ?>!!!</p> -->
 __PUBLIC__：会被替换成当前网站的公共目录 通常是 /Public/    <br>
__ROOT__： 会替换成当前网站的地址（不含域名） <br>
__APP__： 会替换成当前项目的URL地址 （不含域名）<br>
__GROUP__：会替换成当前分组的URL地址 （不含域名）<br>
__URL__： 会替换成当前模块的URL地址（不含域名）<br>
__ACTION__：会替换成当前操作的URL地址 （不含域名）<br>
__SELF__： 会替换成当前的页面URL<br>
</body>
</html>