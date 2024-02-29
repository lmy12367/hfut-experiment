package com.example.countbook;

import android.content.Intent;
import android.os.Bundle;
import android.text.TextUtils;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.Toast;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

import java.util.List;


public class RegisterActivity extends AppCompatActivity implements View.OnClickListener{
    private List<User> userList;
    private String realCode;
    private UserOperator muserOperator;
    private Button mBtRegisteractivityRegister;
    //private RelativeLayout mRlRegisteractivityTop;
    private ImageView mIvRegisteractivityBack;
    //private LinearLayout mLlRegisteractivityBody;
    private EditText mEtRegisteractivityUsername;
    private EditText mEtRegisteractivityPassword1;
    private EditText mEtRegisteractivityPassword2;
    private EditText mEtRegisteractivityPhonecodes;
    private ImageView mIvRegisteractivityShowcode;
    //private RelativeLayout mRlRegisteractivityBottom;

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_register);
        muserOperator=new UserOperator(this);
        init();
        //

        //将验证码用图片的形式显示出来
        mIvRegisteractivityShowcode.setImageBitmap(Code.getInstance().createBitmap());
        realCode = Code.getInstance().getCode().toLowerCase();

    }

    private void init() {
        mBtRegisteractivityRegister = findViewById(R.id.bt_registeractivity_register);
        mIvRegisteractivityBack = findViewById(R.id.iv_registeractivity_back);
        mEtRegisteractivityUsername = findViewById(R.id.et_registeractivity_username);
        mEtRegisteractivityPassword1 = findViewById(R.id.et_registeractivity_password1);
        mEtRegisteractivityPassword2 = findViewById(R.id.et_registeractivity_password2);
        mEtRegisteractivityPhonecodes = findViewById(R.id.et_registeractivity_phoneCodes);
        mIvRegisteractivityShowcode = findViewById(R.id.iv_registeractivity_showCode);
//按钮的点击事件，返回事件，点击二维码事件，注册事件
        mIvRegisteractivityBack.setOnClickListener(this);
        mIvRegisteractivityShowcode.setOnClickListener(this);
        mBtRegisteractivityRegister.setOnClickListener(this);
    }

    @Override
    public void onClick(View v) {
            switch (v.getId()){
                case R.id.iv_registeractivity_back:
                    Intent intent1=new Intent(this,loginActivity.class);
                    startActivity(intent1);
                    finish();
                    break;
                case R.id.iv_registeractivity_showCode:
                    mIvRegisteractivityShowcode.setImageBitmap(Code.getInstance().createBitmap());
                    realCode = Code.getInstance().getCode().toLowerCase();
                    break;
                case R.id.bt_registeractivity_register:
                    String username = mEtRegisteractivityUsername.getText().toString().trim();
                    String password = mEtRegisteractivityPassword1.getText().toString().trim();
                    String password2 = mEtRegisteractivityPassword2.getText().toString().trim();
                    String phoneCode = mEtRegisteractivityPhonecodes.getText().toString().toLowerCase();

                    if(!password.equals(password2)) {
                        Toast.makeText(this, "两次密码不一致，请重新注册", Toast.LENGTH_SHORT).show();
                        break;
                    }

                    if(!TextUtils.isEmpty(username)&&!TextUtils.isEmpty(password)&&!TextUtils.isEmpty(phoneCode)){
                        if(phoneCode.equals(realCode)){
                            User bean=muserOperator.isExit(username);
                            if (bean!=null){
                                Toast.makeText(this, "该用户已存在，请重新注册", Toast.LENGTH_SHORT).show();
                            }else{
                                User bean2=new User(username,password);
                                muserOperator.addUser(bean2);
                                Intent intent2 = new Intent(this, loginActivity.class);
                                Bundle bundle=new Bundle();
                                bundle.putString("username",username);
                                bundle.putString("password",password);
                                intent2.putExtras(bundle);
                                setResult(0x11,intent2);
                                finish();
                                Toast.makeText(this,  "验证通过，注册成功", Toast.LENGTH_SHORT).show();
                            }
                        }else{
                            Toast.makeText(this,  "验证码错误,注册失败", Toast.LENGTH_SHORT).show();
                        }
                    }else{
                        Toast.makeText(this, "未完善信息，注册失败", Toast.LENGTH_SHORT).show();
                    }
                    break;
            }
    }
}
