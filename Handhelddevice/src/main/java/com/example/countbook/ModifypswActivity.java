package com.example.countbook;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.text.TextUtils;
import android.util.Log;
import android.view.View;
import android.view.WindowManager;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;


public class ModifypswActivity extends AppCompatActivity {
    UserOperator muserOperator=null;
    EditText psw=null,npsw1=null,npsw2=null;
    Button btnok=null;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_modifypsw);
        Intent intent=getIntent();
        Bundle bundle=intent.getExtras();
        final String username=bundle.getString("username");
        muserOperator=new UserOperator(ModifypswActivity.this);
        psw=(EditText)findViewById(R.id.edt_psw);
        npsw1=(EditText)findViewById(R.id.edt_npsw1);
        npsw2=(EditText)findViewById(R.id.edt_npsw2);
        btnok=(Button)findViewById(R.id.btn_ok);
        btnok.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String password=psw.getText().toString().trim();
                String npassword1=npsw1.getText().toString().trim();
                String npassword2=npsw2.getText().toString().trim();
                if(!TextUtils.isEmpty(password)&&!TextUtils.isEmpty(npassword1)&&!TextUtils.isEmpty(npassword2)){
                    if(npassword1.equals(npassword2)){
                        User bean=muserOperator.isExit(username);
                        if(bean.password.equals(password)){
                            bean.setPassword(npassword1);
                            muserOperator.updateUser(bean);
                            Toast.makeText(ModifypswActivity.this,"修改成功",Toast.LENGTH_SHORT).show();
                            finish();
                        }else{
                            Toast.makeText(ModifypswActivity.this,"原密码不正确",Toast.LENGTH_SHORT).show();
                        }
                    }else{
                        Toast.makeText(ModifypswActivity.this,"两次密码不一致",Toast.LENGTH_SHORT).show();
                    }
                }else{
                    Toast.makeText(ModifypswActivity.this,"请补充完信息",Toast.LENGTH_SHORT).show();
                }
            }
        });
    }
}
