package com.example.countbook;

import android.app.Fragment;
import android.database.Cursor;
import android.graphics.Color;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;

import com.github.mikephil.charting.animation.Easing;
import com.github.mikephil.charting.charts.PieChart;
import com.github.mikephil.charting.components.Legend;
import com.github.mikephil.charting.data.PieData;
import com.github.mikephil.charting.data.PieDataSet;
import com.github.mikephil.charting.data.PieEntry;
import com.github.mikephil.charting.formatter.PercentFormatter;

import java.util.ArrayList;

public class Chart_Fragment extends Fragment {



    int gongzi=0,jianzhi=0,jiangjin=0;
    int food=0,clothes=0,life=0,qita=0;
    int sum=0,sumshou=0,sumzhi=0;
    private PieChart pieChart;
    private AccountOperator accountOperator;
    Bundle bundle;
    String username;
    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.chart_fragment, null);
        accountOperator=new AccountOperator(view.getContext());
        bundle=getArguments();
        username=bundle.getString("username");
        getsum();

        pieChart=(PieChart)view.findViewById(R.id.pieChart);
        pieChart.setUsePercentValues(true);//设置value是否用显示百分数,默认为false
        pieChart.setDescription("收支情况");//设置描述
        pieChart.setDescriptionTextSize(50);//设置描述字体大小
        pieChart.setDescriptionColor(Color.GREEN);

        pieChart.setExtraOffsets(5, 5, 5, 5);//设置饼状图距离上下左右的偏移量

        pieChart.setDrawCenterText(true);//是否绘制中间的文字
        pieChart.setCenterTextColor(Color.RED);//中间的文字颜色
        pieChart.setCenterTextSize(15);//中间的文字字体大小

        pieChart.setDrawHoleEnabled(true);//是否绘制饼状图中间的圆
        pieChart.setHoleColor(Color.WHITE);//饼状图中间的圆的绘制颜色
        pieChart.setHoleRadius(40f);//饼状图中间的圆的半径大小

        pieChart.setTransparentCircleColor(Color.BLACK);//设置圆环的颜色
        pieChart.setTransparentCircleAlpha(100);//设置圆环的透明度[0,255]
        pieChart.setTransparentCircleRadius(40f);//设置圆环的半径值

        // enable rotation of the chart by touch
        pieChart.setRotationEnabled(true);//设置饼状图是否可以旋转(默认为true)
        pieChart.setRotationAngle(10);//设置饼状图旋转的角度

        pieChart.setHighlightPerTapEnabled(true);//设置旋转的时候点中的tab是否高亮(默认为true)

        //右边小方框部分
        Legend l = pieChart.getLegend(); //设置比例图
        l.setPosition(Legend.LegendPosition.RIGHT_OF_CHART_CENTER);//设置每个tab的显示位置（这个位置是指下图右边小方框部分的位置 ）
//        l.setForm(Legend.LegendForm.LINE);  //设置比例图的形状，默认是方形
        l.setXEntrySpace(0f);
        l.setYEntrySpace(0f);//设置tab之间Y轴方向上的空白间距值
        l.setYOffset(0f);

        //饼状图上字体的设置
        // entry label styling
        pieChart.setDrawEntryLabels(true);//设置是否绘制Label
        pieChart.setEntryLabelColor(Color.rgb(95,158,160));//设置绘制Label的颜色
        pieChart.setEntryLabelTextSize(20f);//设置绘制Label的字体大小

//        pieChart.setOnChartValueSelectedListener(this);//设值点击时候的回调
        pieChart.animateY(3400, Easing.EasingOption.EaseInQuad);//设置Y轴上的绘制动画
        ArrayList<PieEntry> pieEntries = new ArrayList<PieEntry>();

        pieEntries.add(new PieEntry(gongzi, "工资"));
        pieEntries.add(new PieEntry(jiangjin, "奖金"));
        pieEntries.add(new PieEntry(jianzhi, "兼职"));

        pieEntries.add(new PieEntry(food, "伙食"));
        pieEntries.add(new PieEntry(clothes, "服饰"));
        pieEntries.add(new PieEntry(life, "日用品"));
        pieEntries.add(new PieEntry(qita, "其他"));

        String centerText = "净收入\n¥" + (sum);
        pieChart.setCenterText(centerText);//设置圆环中间的文字
        PieDataSet pieDataSet = new PieDataSet(pieEntries, "");
        ArrayList<Integer> colors = new ArrayList<Integer>();

        // 饼图颜色
        colors.add(Color.rgb(205, 205, 205));
        colors.add(Color.rgb(114, 188, 223));
        colors.add(Color.rgb(255, 123, 124));
        colors.add(Color.rgb(57, 135, 200));
        colors.add(Color.rgb(255,20,147));
        colors.add(Color.rgb(255,0,255));
        colors.add(Color.rgb(255,215,0));
        pieDataSet.setColors(colors);

        pieDataSet.setSliceSpace(0f);//设置选中的Tab离两边的距离
        pieDataSet.setSelectionShift(5f);//设置选中的tab的多出来的
        PieData pieData = new PieData();
        pieData.setDataSet(pieDataSet);

        //各个饼状图所占比例数字的设置
        pieData.setValueFormatter(new PercentFormatter());//设置%
        pieData.setValueTextSize(20f);
        pieData.setValueTextColor(Color.rgb(148,0,211));

        pieChart.setData(pieData);
        // undo all highlights
        pieChart.highlightValues(null);
        pieChart.invalidate();

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
        }
        sum=sumshou-sumzhi;
        cursor.close();
    }
}
