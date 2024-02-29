package com.example.countbook;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.BaseAdapter;
import android.widget.GridView;
import android.widget.ImageView;
import android.widget.Toast;

import com.example.countbook.R;

public class HeadActivity extends AppCompatActivity {
    public int[] imageId = new int[]{R.drawable.touxiang1, R.drawable.touxiang2,
            R.drawable.touxiang3, R.drawable.touxiang4, R.drawable.touxiang5
    };


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_head);
        GridView gridView=(GridView)findViewById(R.id.gridView);
        BaseAdapter baseAdapter=new BaseAdapter() {

            @Override
            public int getCount() {
                return imageId.length;
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
                ImageView imageView;
                if(convertView==null){
                    imageView=new ImageView(HeadActivity.this);
                    imageView.setAdjustViewBounds(true);
                    imageView.setMaxHeight(158);
                    imageView.setMaxWidth(150);
                    imageView.setPadding(5, 5, 5, 5);
                }else{
                    imageView=(ImageView)convertView;
                }
                imageView.setImageResource(imageId[position]);
                return imageView;
            }
        };
        gridView.setAdapter(baseAdapter);
        gridView.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                Intent intent=getIntent();
                Bundle bundle=new Bundle();
                bundle.putInt("imageId",imageId[position]);
                intent.putExtras(bundle);
                setResult(0x11,intent);
                finish();
            }
        });
    }
}
