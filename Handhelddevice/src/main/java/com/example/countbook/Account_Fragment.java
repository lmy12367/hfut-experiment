package com.example.countbook;

import android.app.AlertDialog;
import android.app.Fragment;
import android.content.DialogInterface;
import android.database.Cursor;
import android.os.Bundle;
import android.text.TextUtils;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.Button;
import android.widget.DatePicker;
import android.widget.EditText;
import android.widget.ListView;
import android.widget.RadioButton;
import android.widget.Toast;

import androidx.annotation.Nullable;

import java.util.ArrayList;
import java.util.List;

public class Account_Fragment extends Fragment {
    private List<Account> list;
    private AccountOperator accountOperator;
    private AccountAdapter accountAdapter;
    Button btn_shouru;
    Button btn_zhichu;
    Button btn_delete;
    Bundle bundle;
    String username;
    View view;




    @Override
    public void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        Log.i("hello","hello");
    }
//实现长按删除listview里的item事件
    public void onActivityCreated(Bundle savedInstanceState) {
        super.onActivityCreated(savedInstanceState);
        final ListView listView = (ListView) getActivity().findViewById(R.id.lv_main);
        listView.setOnItemLongClickListener(new AdapterView.OnItemLongClickListener() {
            @Override
            public boolean onItemLongClick(AdapterView<?> parent, final View view, final int position, long id) {
                AlertDialog.Builder builder=new AlertDialog.Builder(view.getContext());
                builder.setMessage("确定删除？");
                builder.setTitle("提示");
                final Account[] account = {null};
                builder.setPositiveButton("确定", new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {
                            account[0] =list.get(position);
                            accountOperator.deletebycontent(account[0].content,account[0].author);
                            list.remove(position);
                        accountAdapter.notifyDataSetChanged();
                        Toast.makeText(view.getContext(), "删除"+ account[0].content, Toast.LENGTH_SHORT).show();
                    }
                });
                builder.setNegativeButton("取消", new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {

                    }
                });
                builder.create().show();
                return false;
            }
        });

    }

    //设置添加账单
    @Nullable
    @Override
    public View onCreateView(LayoutInflater inflater, @Nullable ViewGroup container, Bundle savedInstanceState) {
        view=inflater.inflate(R.layout.account_fragment,null);
        Log.i("account:","account");
//获取用户名
        bundle=getArguments();
        username=bundle.getString("username");
        Log.i("username",username);

        btn_shouru=(Button)view.findViewById(R.id.btn_shouru);
        btn_zhichu=(Button)view.findViewById(R.id.btn_zhichu);
        btn_delete=(Button)view.findViewById(R.id.btn_delete);
//设置数据库操作对象
        accountOperator=new AccountOperator(view.getContext());
        list=new ArrayList<>();
        ListView AccountList=(ListView)view.findViewById(R.id.lv_main);
        inin(username);
        accountAdapter=new AccountAdapter(view.getContext(),list);
        AccountList.setAdapter(accountAdapter);
//设置监听事件
        btn_zhichu.setOnClickListener(l);
        btn_shouru.setOnClickListener(l);
        btn_delete.setOnClickListener(l);
        return view;
    }
    // 对监听事件进行监听
    View.OnClickListener l=new View.OnClickListener() {
        @Override
        public void onClick(View v) {
            switch (v.getId()){
                case R.id.btn_zhichu:
                    AlertDialog.Builder builder=new AlertDialog.Builder(getView().getContext());
                    LayoutInflater inflater=LayoutInflater.from(getView().getContext());
                    View viewDialog=inflater.inflate(R.layout.new_cost_data,null);
                    final EditText content=(EditText)viewDialog.findViewById(R.id.et_cost_content);
                    final DatePicker data=(DatePicker)viewDialog.findViewById(R.id.dp_cost_data);
                    final EditText money=(EditText)viewDialog.findViewById(R.id.et_cost_money);
                    final RadioButton rb1=(RadioButton)viewDialog.findViewById(R.id.rb1);
                    final RadioButton rb2=(RadioButton)viewDialog.findViewById(R.id.rb2);
                    final RadioButton rb3=(RadioButton)viewDialog.findViewById(R.id.rb3);
                    final RadioButton rb4=(RadioButton)viewDialog.findViewById(R.id.rb4);


                    builder.setView(viewDialog);
                    builder.setTitle("新消费");
                    builder.setPositiveButton("确认", new DialogInterface.OnClickListener() {
                        @Override
                        public void onClick(DialogInterface dialog, int which) {
                            Account bean = new Account();
                            bean.author = username;
                            bean.content = content.getText().toString();
                            if (!money.getText().toString().equals("")) {
                                bean.money = Integer.parseInt(money.getText().toString());
                                bean.date = data.getYear() + "-" + (data.getMonth() + 1) + "-" + data.getDayOfMonth();
                                if (rb1.isChecked()) {
                                    bean.title = rb1.getText().toString();
                                } else if (rb2.isChecked()) {
                                    bean.title = rb2.getText().toString();
                                } else if (rb3.isChecked()) {
                                    bean.title = rb3.getText().toString();
                                } else if (rb4.isChecked()) {
                                    bean.title = rb4.getText().toString();
                                }
                                if (TextUtils.isEmpty(bean.content) || TextUtils.isEmpty(money.getText().toString()) || TextUtils.isEmpty(bean.date) ||
                                        TextUtils.isEmpty(bean.title)) {
                                    Toast.makeText(view.getContext(), "请把信息填写完整", Toast.LENGTH_SHORT).show();
                                } else {
                                    accountOperator.insert(bean);
                                    list.add(bean);
                                    accountAdapter.notifyDataSetChanged();
                                }
                            }else{
                                Toast.makeText(view.getContext(), "请把信息填写完整", Toast.LENGTH_SHORT).show();
                            }
                        }
                    });
                    builder.setNegativeButton("取消",null);
                    builder.create().show();
                    break;

                case R.id.btn_shouru:
                    AlertDialog.Builder builder2=new AlertDialog.Builder(getView().getContext());
                    LayoutInflater inflater2=LayoutInflater.from(getView().getContext());
                    View viewDialog2=inflater2.inflate(R.layout.new_income_data,null);
                    final EditText content2=(EditText)viewDialog2.findViewById(R.id.et_income_content);
                    final DatePicker data2=(DatePicker)viewDialog2.findViewById(R.id.dp_income_data);
                    final EditText money2=(EditText)viewDialog2.findViewById(R.id.et_income_money);
                    final RadioButton frb1=(RadioButton)viewDialog2.findViewById(R.id.rb1);
                    final RadioButton frb2=(RadioButton)viewDialog2.findViewById(R.id.rb2);
                    final RadioButton frb3=(RadioButton)viewDialog2.findViewById(R.id.rb3);


                    builder2.setView(viewDialog2);
                    builder2.setTitle("新收入");
                    builder2.setPositiveButton("确定", new DialogInterface.OnClickListener() {
                        @Override
                        public void onClick(DialogInterface dialog, int which) {
                            Account bean = new Account();
                            bean.author = username;
                            bean.content = content2.getText().toString();
                            if (!money2.getText().toString().equals("")) {
                                bean.money = Integer.parseInt(money2.getText().toString());
                                bean.date = data2.getYear() + "-" + (data2.getMonth() + 1) + "-" + data2.getDayOfMonth();
                                if (frb1.isChecked()) {
                                    bean.title = frb1.getText().toString();
                                } else if (frb2.isChecked()) {
                                    bean.title = frb2.getText().toString();
                                } else if (frb3.isChecked()) {
                                    bean.title = frb3.getText().toString();
                                }
                                if (TextUtils.isEmpty(bean.content) || TextUtils.isEmpty(money2.getText().toString()) || TextUtils.isEmpty(bean.date) ||
                                        TextUtils.isEmpty(bean.title)) {
                                    Toast.makeText(view.getContext(), "请把信息填写完整", Toast.LENGTH_SHORT).show();
                                } else {
                                    accountOperator.insert(bean);
                                    list.add(bean);
                                    accountAdapter.notifyDataSetChanged();
                                }
                            } else {
                                Toast.makeText(view.getContext(), "请把信息填写完整", Toast.LENGTH_SHORT).show();
                            }
                        }
                    });
                    builder2.setNegativeButton("取消",null);
                    builder2.create().show();
                    break;
                case R.id.btn_delete:
                    accountOperator.deleteall(username);
                    list.clear();
                    accountAdapter.notifyDataSetChanged();
                    break;


            }
        }
    };

    private void inin(String author) {
        Cursor cursor= (Cursor) accountOperator.findall(author);
        if(cursor!=null){
            while(cursor.moveToNext()){
                Account bean=new Account();
                bean.id=cursor.getInt(cursor.getColumnIndex("id"));
                bean.content=cursor.getString(cursor.getColumnIndex("content"));
                bean.money=cursor.getInt(cursor.getColumnIndex("money"));
                bean.date=cursor.getString(cursor.getColumnIndex("date"));
                bean.title=cursor.getString(cursor.getColumnIndex("title"));
                bean.author=cursor.getString(cursor.getColumnIndex("author"));
                list.add(bean);
            }
            cursor.close();
        }
    }

}
