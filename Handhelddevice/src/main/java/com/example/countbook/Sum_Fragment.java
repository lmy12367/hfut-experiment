package com.example.countbook;

import android.app.Fragment;
import android.database.Cursor;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;

import java.util.ArrayList;
import java.util.List;


public class Sum_Fragment extends Fragment {
    Bundle bundle;
    String username;
    AccountOperator accountOperator;
    int sumshou=0;
    int sumzhi=0;
    int gongzi=0,jianzhi=0,jiangjin=0;
    int food=0,clothes=0,life=0,qita=0;
    int sum=0;
    TextView tv_shou;
    TextView tv_zhi;
    TextView tv_gongzi,tv_jiangjin,tv_jianzhi;
    TextView tv_food,tv_clothes,tv_life,tv_qita;
    TextView tv_sum;
    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
        View view=inflater.inflate(R.layout.sum_fragment,null);
        bundle=getArguments();
        username=bundle.getString("username");
        accountOperator=new AccountOperator(view.getContext());
        List<Account> list=new ArrayList<>();
        getsum();
        tv_shou=(TextView)view.findViewById(R.id.tv_sumshouru);
        tv_zhi=(TextView)view.findViewById(R.id.tv_sumzhichu);
        tv_gongzi=(TextView)view.findViewById(R.id.tv_gongzi);
        tv_jiangjin=(TextView)view.findViewById(R.id.tv_jiangjin);
        tv_jianzhi=(TextView)view.findViewById(R.id.tv_jianzhi);
        tv_food=(TextView)view.findViewById(R.id.tv_food);
        tv_clothes=(TextView)view.findViewById(R.id.tv_clothes);
        tv_life=(TextView)view.findViewById(R.id.tv_life);
        tv_qita=(TextView)view.findViewById(R.id.tv_qita);
        tv_sum=(TextView)view.findViewById(R.id.tv_sum);
        //动态数字
        NumAnim.startAnim(tv_shou, sumshou, 1000);     //设置滚动动画持续1秒
        NumAnim.startAnim(tv_zhi, sumzhi, 1000);     //设置滚动动画持续1秒
        NumAnim.startAnim(tv_gongzi, gongzi, 1000);     //设置滚动动画持续1秒
        NumAnim.startAnim(tv_jiangjin, jiangjin, 1000);     //设置滚动动画持续1秒
        NumAnim.startAnim(tv_jianzhi, jianzhi, 1000);     //设置滚动动画持续1秒
        NumAnim.startAnim(tv_food, food, 1000);     //设置滚动动画持续1秒
        NumAnim.startAnim(tv_clothes, clothes, 1000);     //设置滚动动画持续1秒
        NumAnim.startAnim(tv_life, life, 1000);     //设置滚动动画持续1秒
        NumAnim.startAnim(tv_qita, qita, 1000);     //设置滚动动画持续1秒
        NumAnim.startAnim(tv_sum, sum, 1000);     //设置滚动动画持续1秒
        return view;
    }

    private void getsum() {
        Cursor cursor= (Cursor) accountOperator.findall(username);
        while(cursor.moveToNext()){
            String label=cursor.getString(cursor.getColumnIndex("title"));
            int money=cursor.getInt(cursor.getColumnIndex("money"));
            if(label.equals("工资")||label.equals("兼职")||label.equals("奖金")){
                sumshou+=money;
                if(label.equals("工资")){
                    gongzi+=money;
                }else if(label.equals("兼职")){
                    jianzhi+=money;
                }else if(label.equals("奖金")){
                    jiangjin+=money;
                }
            }else{
                sumzhi+=money;
                if(label.equals("伙食")){
                    food+=money;
                }else if(label.equals("服饰")){
                    clothes+=money;
                }else if(label.equals("日用品")){
                    life+=money;
                }else if(label.equals("其他")){
                    qita+=money;
                }
            }
            sum=sumshou-sumzhi;
        }
        cursor.close();
    }
}
