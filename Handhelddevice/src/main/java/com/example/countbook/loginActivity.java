package com.example.countbook;

import android.app.Activity;
import android.app.FragmentManager;
import android.app.FragmentTransaction;
import android.app.Fragment;
import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.text.TextUtils;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import androidx.annotation.Nullable;

public class loginActivity extends Activity implements View.OnClickListener{
    private UserOperator muserOperator;
    private TextView mTvLoginactivityRegister;
    //private RelativeLayout mRlLoginactivityTop;
    private EditText mEtLoginactivityUsername;
    private EditText mEtLoginactivityPassword;
    //private LinearLayout mLlLoginactivityTwo;
    private Button mBtLoginactivityLogin;

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_login);
        muserOperator=new UserOperator(this);
        initView();
    }



    private void initView() {
        mBtLoginactivityLogin = findViewById(R.id.bt_loginactivity_login);
        mTvLoginactivityRegister = findViewById(R.id.tv_loginactivity_register);
        mEtLoginactivityUsername = findViewById(R.id.et_loginactivity_username);
        mEtLoginactivityPassword = findViewById(R.id.et_loginactivity_password);

        mBtLoginactivityLogin.setOnClickListener(this);
        mTvLoginactivityRegister.setOnClickListener(this);
    }

    @Override
    public void onClick(View v) {
        switch (v.getId()){
            case R.id.tv_loginactivity_register:
                startActivityForResult(new Intent(this,RegisterActivity.class),0x11);
                break;
            case R.id.bt_loginactivity_login:
                String username=mEtLoginactivityUsername.getText().toString().trim();
                String password=mEtLoginactivityPassword.getText().toString().trim();
                User bean=muserOperator.isExit(username);
                if(!TextUtils.isEmpty(username)&&!TextUtils.isEmpty(password)){
                    if(bean!=null&&bean.password.equals(password)){
                        Toast.makeText(this, "登录成功", Toast.LENGTH_SHORT).show();
                        Intent intent = new Intent(this, MainActivity.class);
                        Bundle bundle=new Bundle();
                        bundle.putString("username",username);
                        //设置向Account_Fragment传递参数
                        Fragment fragment=new Account_Fragment();
                        fragment.setArguments(bundle);
                        FragmentManager fm = getFragmentManager();   // 获取Fragment
                        FragmentTransaction ft = fm.beginTransaction();
                        ft.commit();
                        //传参结束
                        intent.putExtras(bundle);
                        startActivity(intent);
                        finish();
                    }else{
                        Toast.makeText(this, "用户名或密码不正确，请重新输入", Toast.LENGTH_SHORT).show();
                    }
                }else{
                    Toast.makeText(this, "请输入你的用户名或密码", Toast.LENGTH_SHORT).show();
                }
                break;
        }
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        if(requestCode==0x11&&resultCode==0x11)
        {
            Bundle bundle=data.getExtras();
            String username=bundle.getString("username");
            String password=bundle.getString("password");
            mEtLoginactivityPassword.setText(password);
            mEtLoginactivityUsername.setText(username);
        }
    }
}
