package com.example.countbook;

import android.content.Context;
import android.graphics.Color;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.TextView;

import java.util.List;

public class AccountAdapter extends BaseAdapter {
    private List<Account> mlist;
    private Context mContext;
    private LayoutInflater mlayoutInflater;
    public AccountAdapter(Context context,List<Account> list){
        mContext=context;
        mlist=list;
        mlayoutInflater=LayoutInflater.from(context);
    }





    @Override
    public int getCount() {
        return mlist.size();
    }

    @Override
    public Object getItem(int position) {
        return position;
    }

    @Override
    public long getItemId(int position) {
        return position;
    }

    @Override
    public View getView(int position, View convertView, ViewGroup parent) {
        final ViewHolder viewHolder;
        if(convertView==null){
            viewHolder=new ViewHolder();
            convertView=mlayoutInflater.inflate(R.layout.item,null);
            viewHolder.mContent=convertView.findViewById(R.id.tv_content);
            viewHolder.mDate=convertView.findViewById(R.id.tv_date);
            viewHolder.mMoney=convertView.findViewById(R.id.tv_money);
            convertView.setTag(viewHolder);
        }else{
            viewHolder=(ViewHolder)convertView.getTag();
        }
        Account bean=mlist.get(position);
        if (bean.title.equals("工资")||bean.title.equals("兼职")||bean.title.equals("奖金")){
            viewHolder.mMoney.setTextColor(Color.GREEN);
        }else{
            viewHolder.mMoney.setTextColor(Color.RED);
        }
        viewHolder.mContent.setText(bean.content);
        viewHolder.mDate.setText(bean.date);
        viewHolder.mMoney.setText(Integer.toString(bean.money));
        return convertView;
    }
    private static class ViewHolder{
        public TextView mContent;
        public TextView mDate;
        public TextView mMoney;
    }
}
