<!DOCTYPE html> 
<html>
<link href="./email2.css" rel="stylesheet" type="text/css" >
<title>登录</title>


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
		<p class="babyheader">账号登录</p>
		<form action="signin.php" method="post">
			<input type="text" class="textbox"  name="id" placeholder="请输入ID"/>
			<br><br>
			<input type="password" class="textbox" name="password" placeholder="请输入密码"/>
			<br><br>
			<input type="submit" class="submitbuttom" name="submit" value="登录"/>
			<br><br>
		</form>
		<a id="signin"href="email.php">注册</a>
	</div>
</div>


<div class="bottom">
	<ul>
		<li>关于沸点  |</li>   
		<li> |</li>   
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
$con=@mysql_connect("localhost","root","123","email");
//echo"连接成功";
if(isset($_POST['submit']))
{
	 $id=$_POST['id'];
	 $password=$_POST['password'];
	 $sql="select * from account where id=".$id." and password=".$password."";
	 //mysql_query() 函数执行一条 MySQL 查询
	 $query=@mysql_query($sql)or die(mysql_error());
	 $array=@mysql_fetch_array($query);
	 if(!empty($array))//数组不为空
	 {
			SESSION_start();
			$_SESSION['id']=$id;
			if(isset($_SESSION['id'])&&!empty($_SESSION['id'])){
				echo "<script>alert('登录成功');location.href='email2.php'</script>";
			}
	 }
	 else
	 {
			echo "<script>alert('请先注册')</script>";
	 }
}
?>


