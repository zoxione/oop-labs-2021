
namespace Client
{
    partial class Menu
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.buttonPushStack = new System.Windows.Forms.Button();
            this.labelMenu = new System.Windows.Forms.Label();
            this.labelStack = new System.Windows.Forms.Label();
            this.textBoxStack = new System.Windows.Forms.TextBox();
            this.treeStack = new System.Windows.Forms.TreeView();
            this.buttonPopStack = new System.Windows.Forms.Button();
            this.labelISEMPTY = new System.Windows.Forms.Label();
            this.buttonPopQueue = new System.Windows.Forms.Button();
            this.treeQueue = new System.Windows.Forms.TreeView();
            this.textBoxQueue = new System.Windows.Forms.TextBox();
            this.labelQueue = new System.Windows.Forms.Label();
            this.buttonPushQueue = new System.Windows.Forms.Button();
            this.labelFRONT = new System.Windows.Forms.Label();
            this.labelIsEmptyStack = new System.Windows.Forms.Label();
            this.labelIsEmptyQueue = new System.Windows.Forms.Label();
            this.labelFrontQueue = new System.Windows.Forms.Label();
            this.labelCOUNT = new System.Windows.Forms.Label();
            this.labelSIZE = new System.Windows.Forms.Label();
            this.labelSizeQueue = new System.Windows.Forms.Label();
            this.labelSizeStack = new System.Windows.Forms.Label();
            this.labelCountQueue = new System.Windows.Forms.Label();
            this.labelCountStack = new System.Windows.Forms.Label();
            this.labelFrontStack = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // buttonPushStack
            // 
            this.buttonPushStack.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.buttonPushStack.Location = new System.Drawing.Point(101, 388);
            this.buttonPushStack.Margin = new System.Windows.Forms.Padding(0);
            this.buttonPushStack.Name = "buttonPushStack";
            this.buttonPushStack.Size = new System.Drawing.Size(26, 26);
            this.buttonPushStack.TabIndex = 0;
            this.buttonPushStack.Text = "+";
            this.buttonPushStack.UseVisualStyleBackColor = true;
            this.buttonPushStack.Click += new System.EventHandler(this.buttonPushStack_Click);
            // 
            // labelMenu
            // 
            this.labelMenu.AutoSize = true;
            this.labelMenu.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.labelMenu.Location = new System.Drawing.Point(365, 35);
            this.labelMenu.Name = "labelMenu";
            this.labelMenu.Size = new System.Drawing.Size(66, 25);
            this.labelMenu.TabIndex = 1;
            this.labelMenu.Text = "Menu";
            // 
            // labelStack
            // 
            this.labelStack.AutoSize = true;
            this.labelStack.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.labelStack.Location = new System.Drawing.Point(61, 74);
            this.labelStack.Name = "labelStack";
            this.labelStack.Size = new System.Drawing.Size(55, 24);
            this.labelStack.TabIndex = 2;
            this.labelStack.Text = "Stack";
            // 
            // textBoxStack
            // 
            this.textBoxStack.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.textBoxStack.Location = new System.Drawing.Point(12, 388);
            this.textBoxStack.Name = "textBoxStack";
            this.textBoxStack.Size = new System.Drawing.Size(76, 26);
            this.textBoxStack.TabIndex = 3;
            // 
            // treeStack
            // 
            this.treeStack.Location = new System.Drawing.Point(12, 101);
            this.treeStack.Name = "treeStack";
            this.treeStack.Size = new System.Drawing.Size(153, 273);
            this.treeStack.TabIndex = 8;
            // 
            // buttonPopStack
            // 
            this.buttonPopStack.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.buttonPopStack.Location = new System.Drawing.Point(139, 388);
            this.buttonPopStack.Margin = new System.Windows.Forms.Padding(0);
            this.buttonPopStack.Name = "buttonPopStack";
            this.buttonPopStack.Size = new System.Drawing.Size(26, 26);
            this.buttonPopStack.TabIndex = 9;
            this.buttonPopStack.Text = "-";
            this.buttonPopStack.UseVisualStyleBackColor = true;
            this.buttonPopStack.Click += new System.EventHandler(this.buttonPopStack_Click);
            // 
            // labelISEMPTY
            // 
            this.labelISEMPTY.AutoSize = true;
            this.labelISEMPTY.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.labelISEMPTY.Location = new System.Drawing.Point(354, 165);
            this.labelISEMPTY.Name = "labelISEMPTY";
            this.labelISEMPTY.Size = new System.Drawing.Size(96, 24);
            this.labelISEMPTY.TabIndex = 10;
            this.labelISEMPTY.Text = "IS EMPTY";
            // 
            // buttonPopQueue
            // 
            this.buttonPopQueue.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.buttonPopQueue.Location = new System.Drawing.Point(762, 388);
            this.buttonPopQueue.Margin = new System.Windows.Forms.Padding(0);
            this.buttonPopQueue.Name = "buttonPopQueue";
            this.buttonPopQueue.Size = new System.Drawing.Size(26, 26);
            this.buttonPopQueue.TabIndex = 15;
            this.buttonPopQueue.Text = "-";
            this.buttonPopQueue.UseVisualStyleBackColor = true;
            this.buttonPopQueue.Click += new System.EventHandler(this.buttonPopQueue_Click);
            // 
            // treeQueue
            // 
            this.treeQueue.Location = new System.Drawing.Point(635, 101);
            this.treeQueue.Name = "treeQueue";
            this.treeQueue.Size = new System.Drawing.Size(153, 273);
            this.treeQueue.TabIndex = 14;
            // 
            // textBoxQueue
            // 
            this.textBoxQueue.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.textBoxQueue.Location = new System.Drawing.Point(635, 388);
            this.textBoxQueue.Name = "textBoxQueue";
            this.textBoxQueue.Size = new System.Drawing.Size(76, 26);
            this.textBoxQueue.TabIndex = 13;
            // 
            // labelQueue
            // 
            this.labelQueue.AutoSize = true;
            this.labelQueue.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.labelQueue.Location = new System.Drawing.Point(681, 74);
            this.labelQueue.Name = "labelQueue";
            this.labelQueue.Size = new System.Drawing.Size(69, 24);
            this.labelQueue.TabIndex = 12;
            this.labelQueue.Text = "Queue";
            // 
            // buttonPushQueue
            // 
            this.buttonPushQueue.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.buttonPushQueue.Location = new System.Drawing.Point(724, 388);
            this.buttonPushQueue.Margin = new System.Windows.Forms.Padding(0);
            this.buttonPushQueue.Name = "buttonPushQueue";
            this.buttonPushQueue.Size = new System.Drawing.Size(26, 26);
            this.buttonPushQueue.TabIndex = 11;
            this.buttonPushQueue.Text = "+";
            this.buttonPushQueue.UseVisualStyleBackColor = true;
            this.buttonPushQueue.Click += new System.EventHandler(this.buttonPushQueue_Click);
            // 
            // labelFRONT
            // 
            this.labelFRONT.AutoSize = true;
            this.labelFRONT.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.labelFRONT.Location = new System.Drawing.Point(364, 231);
            this.labelFRONT.Name = "labelFRONT";
            this.labelFRONT.Size = new System.Drawing.Size(76, 24);
            this.labelFRONT.TabIndex = 16;
            this.labelFRONT.Text = "FRONT";
            // 
            // labelIsEmptyStack
            // 
            this.labelIsEmptyStack.AutoSize = true;
            this.labelIsEmptyStack.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.labelIsEmptyStack.Location = new System.Drawing.Point(243, 165);
            this.labelIsEmptyStack.Name = "labelIsEmptyStack";
            this.labelIsEmptyStack.Size = new System.Drawing.Size(42, 24);
            this.labelIsEmptyStack.TabIndex = 17;
            this.labelIsEmptyStack.Text = "true";
            // 
            // labelIsEmptyQueue
            // 
            this.labelIsEmptyQueue.AutoSize = true;
            this.labelIsEmptyQueue.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.labelIsEmptyQueue.Location = new System.Drawing.Point(520, 165);
            this.labelIsEmptyQueue.Name = "labelIsEmptyQueue";
            this.labelIsEmptyQueue.Size = new System.Drawing.Size(42, 24);
            this.labelIsEmptyQueue.TabIndex = 18;
            this.labelIsEmptyQueue.Text = "true";
            // 
            // labelFrontQueue
            // 
            this.labelFrontQueue.AutoSize = true;
            this.labelFrontQueue.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.labelFrontQueue.Location = new System.Drawing.Point(531, 231);
            this.labelFrontQueue.Name = "labelFrontQueue";
            this.labelFrontQueue.Size = new System.Drawing.Size(0, 24);
            this.labelFrontQueue.TabIndex = 19;
            // 
            // labelCOUNT
            // 
            this.labelCOUNT.AutoSize = true;
            this.labelCOUNT.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.labelCOUNT.Location = new System.Drawing.Point(364, 357);
            this.labelCOUNT.Name = "labelCOUNT";
            this.labelCOUNT.Size = new System.Drawing.Size(77, 24);
            this.labelCOUNT.TabIndex = 20;
            this.labelCOUNT.Text = "COUNT";
            // 
            // labelSIZE
            // 
            this.labelSIZE.AutoSize = true;
            this.labelSIZE.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.labelSIZE.Location = new System.Drawing.Point(375, 293);
            this.labelSIZE.Name = "labelSIZE";
            this.labelSIZE.Size = new System.Drawing.Size(51, 24);
            this.labelSIZE.TabIndex = 21;
            this.labelSIZE.Text = "SIZE";
            // 
            // labelSizeQueue
            // 
            this.labelSizeQueue.AutoSize = true;
            this.labelSizeQueue.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.labelSizeQueue.Location = new System.Drawing.Point(531, 293);
            this.labelSizeQueue.Name = "labelSizeQueue";
            this.labelSizeQueue.Size = new System.Drawing.Size(20, 24);
            this.labelSizeQueue.TabIndex = 22;
            this.labelSizeQueue.Text = "0";
            // 
            // labelSizeStack
            // 
            this.labelSizeStack.AutoSize = true;
            this.labelSizeStack.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.labelSizeStack.Location = new System.Drawing.Point(254, 293);
            this.labelSizeStack.Name = "labelSizeStack";
            this.labelSizeStack.Size = new System.Drawing.Size(20, 24);
            this.labelSizeStack.TabIndex = 23;
            this.labelSizeStack.Text = "0";
            // 
            // labelCountQueue
            // 
            this.labelCountQueue.AutoSize = true;
            this.labelCountQueue.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.labelCountQueue.Location = new System.Drawing.Point(531, 357);
            this.labelCountQueue.Name = "labelCountQueue";
            this.labelCountQueue.Size = new System.Drawing.Size(20, 24);
            this.labelCountQueue.TabIndex = 24;
            this.labelCountQueue.Text = "0";
            // 
            // labelCountStack
            // 
            this.labelCountStack.AutoSize = true;
            this.labelCountStack.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.labelCountStack.Location = new System.Drawing.Point(254, 357);
            this.labelCountStack.Name = "labelCountStack";
            this.labelCountStack.Size = new System.Drawing.Size(20, 24);
            this.labelCountStack.TabIndex = 25;
            this.labelCountStack.Text = "0";
            // 
            // labelFrontStack
            // 
            this.labelFrontStack.AutoSize = true;
            this.labelFrontStack.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.labelFrontStack.Location = new System.Drawing.Point(254, 231);
            this.labelFrontStack.Name = "labelFrontStack";
            this.labelFrontStack.Size = new System.Drawing.Size(0, 24);
            this.labelFrontStack.TabIndex = 26;
            // 
            // Menu
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.labelFrontStack);
            this.Controls.Add(this.labelCountStack);
            this.Controls.Add(this.labelCountQueue);
            this.Controls.Add(this.labelSizeStack);
            this.Controls.Add(this.labelSizeQueue);
            this.Controls.Add(this.labelSIZE);
            this.Controls.Add(this.labelCOUNT);
            this.Controls.Add(this.labelFrontQueue);
            this.Controls.Add(this.labelIsEmptyQueue);
            this.Controls.Add(this.labelIsEmptyStack);
            this.Controls.Add(this.labelFRONT);
            this.Controls.Add(this.buttonPopQueue);
            this.Controls.Add(this.treeQueue);
            this.Controls.Add(this.textBoxQueue);
            this.Controls.Add(this.labelQueue);
            this.Controls.Add(this.buttonPushQueue);
            this.Controls.Add(this.labelISEMPTY);
            this.Controls.Add(this.buttonPopStack);
            this.Controls.Add(this.treeStack);
            this.Controls.Add(this.textBoxStack);
            this.Controls.Add(this.labelStack);
            this.Controls.Add(this.labelMenu);
            this.Controls.Add(this.buttonPushStack);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.MaximizeBox = false;
            this.Name = "Menu";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "Menu";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.Menu_FormClosing);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button buttonPushStack;
        private System.Windows.Forms.Label labelMenu;
        private System.Windows.Forms.Label labelStack;
        private System.Windows.Forms.TextBox textBoxStack;
        private System.Windows.Forms.TreeView treeStack;
        private System.Windows.Forms.Button buttonPopStack;
        private System.Windows.Forms.Label labelISEMPTY;
        private System.Windows.Forms.Button buttonPopQueue;
        private System.Windows.Forms.TreeView treeQueue;
        private System.Windows.Forms.TextBox textBoxQueue;
        private System.Windows.Forms.Label labelQueue;
        private System.Windows.Forms.Button buttonPushQueue;
        private System.Windows.Forms.Label labelFRONT;
        private System.Windows.Forms.Label labelIsEmptyStack;
        private System.Windows.Forms.Label labelIsEmptyQueue;
        private System.Windows.Forms.Label labelFrontQueue;
        private System.Windows.Forms.Label labelCOUNT;
        private System.Windows.Forms.Label labelSIZE;
        private System.Windows.Forms.Label labelSizeQueue;
        private System.Windows.Forms.Label labelSizeStack;
        private System.Windows.Forms.Label labelCountQueue;
        private System.Windows.Forms.Label labelCountStack;
        private System.Windows.Forms.Label labelFrontStack;
    }
}