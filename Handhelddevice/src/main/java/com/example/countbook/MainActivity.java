package com.example.countbook;

import android.app.Activity;
import android.app.Fragment;
import android.app.FragmentManager;
import android.app.FragmentTransaction;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.ImageView;


public class MainActivity extends Activity{
    Bundle bundle=null;
    ImageView imageView1;
    ImageView imageView2;
    ImageView imageView3;
    ImageView imageView4;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Log.i("main:","main");

        Intent intent=getIntent();
        //获取bundle
        bundle=intent.getExtras();
        //将数据传入到第一个记账Account_Fragment同时将fragment进行切换到记账布局
        Fragment fragment = new Account_Fragment();
        fragment.setArguments(bundle);//数据传递到fragment中
        FragmentManager fm = getFragmentManager();   // 获取Fragment
        FragmentTransaction ft = fm.beginTransaction();
        ft.replace(R.id.fragment,fragment);
        ft.commit();


        imageView1 = (ImageView) findViewById(R.id.image1);//获取布局文件的第一个导航图片
        imageView2 = (ImageView) findViewById(R.id.image2);//获取布局文件的第二个导航图片
        imageView3 = (ImageView) findViewById(R.id.image3);//获取布局文件的第三个导航图片
        imageView4 = (ImageView) findViewById(R.id.image4);//获取布局文件的第四个导航图片

        imageView1.setImageResource(R.drawable.bottom_1);

        imageView1.setOnClickListener(l);//为第一个导航图片添加单机事件
        imageView2.setOnClickListener(l);//为第二个导航图片添加单机事件
        imageView3.setOnClickListener(l);//为第三个导航图片添加单机事件
        imageView4.setOnClickListener(l);//为第四个导航图片添加单机事件
    }
    //创建单机事件监听器
    View.OnClickListener l = new View.OnClickListener() {
        @Override
        public void onClick(View v) {
            imageView1.setImageResource(R.drawable.copy_1);
            imageView2.setImageResource(R.drawable.copy_2);
            imageView3.setImageResource(R.drawable.copy_3);
            imageView4.setImageResource(R.drawable.bottom_4);
            FragmentManager fm = getFragmentManager();   // 获取Fragment
            FragmentTransaction ft = fm.beginTransaction(); // 开启一个事务
            Fragment f = null; //为Fragment初始化
            switch (v.getId()) {    //通过获取点击的id判断点击了哪个张图片
                case R.id.image1:
                    f = new Account_Fragment(); //创建第一个Fragment
                    imageView1.setImageResource(R.drawable.bottom_1);
                    break;
                case R.id.image2:
                    f = new Sum_Fragment();//创建第二个Fragment
                    imageView2.setImageResource(R.drawable.bottom_2);
                    break;
                case R.id.image3:
                    f = new Chart_Fragment();//创建第三个Fragment
                    imageView3.setImageResource(R.drawable.bottom_3);
                    break;
                case R.id.image4:
                    f = new Me_Fragment();//创建第四个Fragment
                    imageView4.setImageResource(R.drawable.copy_4);
                    break;
                default:
                    break;
            }
            if(bundle!=null)
                f.setArguments(bundle);
            ft.replace(R.id.fragment,f); //替换Fragment
            ft.commit(); //提交事务
        }
    };
}
