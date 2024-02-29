package com.example.countbook;

import android.app.Fragment;
import android.content.Intent;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;


public class Me_Fragment extends Fragment{
    String username=null;
    TextView tv_username=null;
    Button btn_img=null;
    TextView tv_psw=null;
    TextView tv_exit=null;
    ImageView img=null;
    UserOperator muserOperator;
    View view=null;
    Bundle bundle=null;
    @Override
    public void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        bundle=getArguments();
        username=bundle.getString("username");
    }

    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
        view=inflater.inflate(R.layout.me_fragment,null);
        tv_username=(TextView)view.findViewById(R.id.tv_username);
        tv_username.setText(username);
        img=(ImageView)view.findViewById(R.id.img);
        btn_img=(Button)view.findViewById(R.id.btn_img);
        tv_psw=(TextView)view.findViewById(R.id.tv_updatepsw);
        tv_exit=(TextView)view.findViewById(R.id.tv_exit);
        muserOperator=new UserOperator(view.getContext());
        img.setImageResource(R.drawable.touxiang1);
        btn_img.setOnClickListener(l);
        tv_psw.setOnClickListener(l);
        tv_exit.setOnClickListener(l);
        return view;
    }

    View.OnClickListener l=new View.OnClickListener() {
        @Override
        public void onClick(View v) {
            switch (v.getId()){
                case R.id.btn_img:
                    Intent intent=new Intent(view.getContext(),HeadActivity.class);
                    startActivityForResult(intent,0x11);
                    break;
                case R.id.tv_exit:
                    Intent intent1=new Intent(view.getContext(),loginActivity.class);
                    startActivity(intent1);
                    break;
                case R.id.tv_updatepsw:
                    Intent intent2=new Intent(view.getContext(),ModifypswActivity.class);
                    intent2.putExtras(bundle);
                    startActivity(intent2);
            }
        }
    };



    @Override
    public void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        if(requestCode==0x11&&resultCode==0x11){
            Bundle bundle=data.getExtras();
            int image=bundle.getInt("imageId");
            img.setImageResource(image);
        }
    }
}
