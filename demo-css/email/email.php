<!DOCTYPE html> 
<html>
<link href="./email2.css" rel="stylesheet" type="text/css" >
<title>注册</title>


<body>
<div class="top">
	<div class="img1">
		<img src="20170305213714.jpg">
	</div>
	<div class="header">
	<ul>
		<li>基本版|</li>
		<li>English|</li>
		<li>手机版|</li>
		<li>企业邮箱</li>
	</ul>
	</div>
</div>


<div class="center">
	<div class="text">
		<p><strong>QQ邮箱</strong></p>
		<p> 可怜白雪曲，未遇知音人。
			恓惶戎旅下，蹉跎淮海滨。
			涧树含朝雨，山鸟哢馀春。
			我有一瓢酒，可以慰风尘。</P>
	</div>
	<div class="img2">
		<img src="tim.jpg" width="350" height="500">
	</div>
	<div class="signin">
		<p class="babyheader">账号注册</p>
		<form action="email.php" method="post">
			<input type="text" class="textbox"  name="id" placeholder="请输入ID"/>
			<br><br>
			<input type="password" class="textbox" name="password" placeholder="请输入密码"/>
			<br><br>
			<input type="submit" class="submitbuttom" name="submit" value="注册"/>
			<br><br>
		</form>
		<a id="register"href="email2.php">返回登录</a>
	</div>
</div>


<div class="bottom">
	<ul>
		<li>关于沸点|</li>
		<li>服务条款|</li>
		<li>客服中心|</li>
		<li>联系我们|</li>
		<li>帮助中心|</li>
		<li>2010-2017Feidian Inc.All Rights Reserved</li>
	</ul>
</div>
<li></li>


</body>
</html>

</html>


<?php
$con =@mysqli_connect("localhost","root","123","email")or die("连接错误");
//echo "连接成功";
if(isset($_POST['submit'])){
	$sql="insert into account(id,password) 
	      values
		  ('$_POST[id]','$_POST[password]')";
    mysqli_query($con,$sql);
	echo"<script>alert('注册成功');location.href='email.php'</script>";
}
?>