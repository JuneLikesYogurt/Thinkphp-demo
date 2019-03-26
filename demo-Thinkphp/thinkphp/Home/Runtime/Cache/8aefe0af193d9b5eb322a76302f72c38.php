<?php if (!defined('THINK_PATH')) exit();?><!DOCTYPE html>
<html>
<head>
	<title>index-bbs</title>
	<script type="text/javascript">
		function jump() {
			window.location="/thinkphp/index.php/bbs/add";
		}
	</script>
</head>
<body>
    <form action='__URL__/search' method='post'>
        留言内容：<input type="text" name="content"/>
        <input type="submit" value="查询"/>
        <br><br>
    </form>
    
    <table border="1" width="500" align="center">
    	<tr>
    	    <!-- <th>id</th> -->
    	    <th>username</th>
    	    <th>content</th>
    	    <th>操作</th>
    	</tr>
    	<?php if(is_array($data)): $i = 0; $__LIST__ = $data;if( count($__LIST__)==0 ) : echo "" ;else: foreach($__LIST__ as $key=>$vo): $mod = ($i % 2 );++$i;?><tr>
                <!-- <td> <?php echo ($vo["id"]); ?> </td> -->
                <td> <?php echo ($vo["username"]); ?> </td>
                <td> <?php echo ($vo["content"]); ?> </td>
                <td> <a href="/thinkphp/index.php/bbs/del/id/<?php echo ($vo["id"]); ?>">删除</a> | <a href="/thinkphp/index.php/bbs/modify">修改</a> </td>
            </tr><?php endforeach; endif; else: echo "" ;endif; ?>
    </table>
    <center>
	    <button onclick="jump()">添加留言</button>
    </center>
    
</body>
</html>