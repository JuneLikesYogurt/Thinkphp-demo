<?php
// 本类由系统自动生成，仅供测试用途
class IndexAction extends Action {
    public function index(){
		//echo 'hello '.$_GET['name'];
		//$m=new Model('User');

		//$m=M('User');

		//读取数据
		//$arr=$m->select();
		//$arr=$m->find(2);
		//$arr=$m->where('id=2')->getField('username');
        //var_dump($arr);

        //创建数据
        //$m->username='白河愁';
		//m->sex=1;
        //$m->add();
		
        //删除数据
        //$m->delete(2);
        //$m->where('id=5')->delete();
        //echo $count;

        //更新数据
        /*$data['id']=1;
        $data['username']='zhangsan6';
        $count=$m->save($data);//返回受影响行数
        echo $count;*/

		//$this->name='zzz';
		//$this->display('./Public/error.html','text/xml');

        //$this->show('<b>这里显示了加粗的字体</b>');

        /*$content=$this->fetch('Public:error');
        dump($content);
        $content=str_replace('h2', 'i',$content); 
        $this->show($content);*/

        //$this->assign('name','Tom');
        $this->name='Marry';
        $this->display();
    }
    public function show2(){
        $m=M('User');
        //echo $m->where('id=8')->getField('username');

        //字符串
        //$arr=$m->where("sex=0 and username='蓝海忧'")->find();

        /*数组*/
        /*$data['sex']=0;
        $data['username']='蓝海忧';
        $data['_logic_']='or';//默认为and关系
        $arr=$m->where($data)->find();*/

        //表达式查询
        //$data['id']=array('lt',7);
        //$data['username']=array('like','%白%');//模糊查询 like notlike
        //$data['username']=array('like',array('%白%','%7%'));
        //$data['id']=array('between',array(9,12));
        //$arr=$m->where($data)->select();

        //区间查询
        /*$data['id']=array(array('gt',9),array('lt',12));
        $arr=$m->where($data)->select();*/

        //统计查询
        //$c=$m->where("username='李白'")->count();
        //$data['username']='李白';
        //$c=$m->where($data)->count();
        /*$c=$m->max('id');
        echo $c;*/

        //SQL直接查询
        //$result=$m->query("select * from tp_user where id>9");
        $result=$m->execute("insert into tp_user(`username`) values('李商隐')");
        var_dump($result);

        //var_dump($arr);
        $this->display();
    }
}