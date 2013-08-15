package com.okto.vo.editor;

import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.LayoutManager;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.List;
import java.util.Vector;

import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JTable;
import javax.swing.JTextArea;
import javax.swing.table.DefaultTableModel;

import javax.swing.JScrollPane;
import javax.swing.ScrollPaneConstants;


public class QueryForm extends JFrame {

	private static final long serialVersionUID = 1L;

	private QueryForm frame = this;
	private JTextArea query = new JTextArea();
	private JTable result = new JTable(new DefaultTableModel());
	private JButton execute = new JButton();
	private LayoutManager layout;


	public static void main(String[] args) {
		new QueryForm().setVisible(true);
	}

	public LayoutManager createLayout() {
		return new BorderLayout();
	}

	public QueryForm() {

		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setSize(700, 500);
		this.setLocationByPlatform(true);

		this.layout = this.createLayout();
		this.setLayout(this.layout);

		this.query.setBorder(BorderFactory.createEtchedBorder());
                this.query.setRows(5);
                this.query.setColumns(20);
		//this.query.setPreferredSize(new Dimension(300, 100));
		this.query.setFont(Font.decode("Courier 14"));

                JScrollPane jsp = new JScrollPane();
                jsp.setVerticalScrollBarPolicy(ScrollPaneConstants.VERTICAL_SCROLLBAR_ALWAYS);
                jsp.setHorizontalScrollBarPolicy(ScrollPaneConstants.HORIZONTAL_SCROLLBAR_ALWAYS);
                jsp.setViewportView(this.query);

                this.query.setLineWrap(true);

		this.add(jsp, BorderLayout.SOUTH);

		this.execute.setText("Executar");
		this.execute.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				frame.executeQuery();
			}
		});
		this.add(this.execute, BorderLayout.NORTH);

		this.result.setBorder(BorderFactory.createRaisedBevelBorder());
		this.add(new JScrollPane(this.result));
	}

	@SuppressWarnings("unchecked")
	private void executeQuery() {

		try {
			DefaultTableModel model = (DefaultTableModel) this.result.getModel();
			model.getDataVector().clear();
		} catch (Exception e) {
			System.out.println(this.query.getText());
			e.printStackTrace();
		}
	}
}
