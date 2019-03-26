<?php if (!defined('THINK_PATH')) exit();?><!DOCTYPE html>
<html>
<head>
	<title>Index</title>
	<style type="text/css">
		*{
			margin: 0;
			padding:0;
		}
		form{
			padding-top: 100px;
			width: 300px;
			margin: 0 auto;
		}
	</style>
	<script type="text/javascript">
		function sub(){
			var ou=document.myForm.username;
			var op=document.myForm.password;
			var oc=document.myForm.code;
			if(ou.value==''||op.value==''||oc.value==''){
				alert('用户名或密码或验证码不能为空');
			}else{
				document.myForm.submit();
			}
		}
	</script>
</head>
<body>
	<form action="__URL__/do_login" method="post">
		用户名：<input type="text" name="username"><br>
		密 码：&nbsp <input type="password" name="password" onclick="this.src=this.src+'?'+Math.radom()"><br>
		验证码：<input type="text" name="code" >
				<img src="__APP__/Public/code">
		<br>
		<img src="__PUBLIC__/images/login.gif" onclick="sub()">
	</form>
</body>
</html>