<?php if (!defined('THINK_PATH')) exit();?><!DOCTYPE html>
<html>
<head>
	<title>index-User</title>
	<script type="text/javascript">
		function jump() {
			window.location="/thinkphp/index.php/User/add";
		}
	</script>
</head>
<body>
    <form action='__URL__/search' method='post'>
        用户名：<input type="text" name="username"/>
        性别：<input type="radio" name="sex" value="1" />男<input type="radio" name="sex" value="0"/>女
        <input type="submit" value="搜索"/>
    </form>
    <br>
    <table border="1" width="500" align="center">
    	<tr>
    	    <th>id</th>
    	    <th>username</th>
    	    <th>sex</th>
    	    <th>操作</th>
    	</tr>
    	<?php if(is_array($data)): $i = 0; $__LIST__ = $data;if( count($__LIST__)==0 ) : echo "" ;else: foreach($__LIST__ as $key=>$vo): $mod = ($i % 2 );++$i;?><tr>
                <td> <?php echo ($vo["id"]); ?> </td>
                <td> <?php echo ($vo["username"]); ?> </td>
                <td> <?php echo ($vo["sex"]); ?> </td>
                <td> <a href="/thinkphp/index.php/User/del/id/<?php echo ($vo["id"]); ?>">删除</a> | <a href="/thinkphp/index.php/User/modify">修改</a> </td>
            </tr><?php endforeach; endif; else: echo "" ;endif; ?>
    </table>
    <center>
	    <button onclick="jump()">添加用户</button>
    </center>
    
</body>
</html>